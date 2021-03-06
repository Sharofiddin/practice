#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


struct Address {
	int id;
	int set;
	char *name;
	char *email;
};

struct Database {
	unsigned long max_data;
	unsigned long max_rows;
	struct Address **rows;
};

struct Connection {
	FILE *file;
	struct Database *db;
};

void Database_close( struct Connection *conn){
	if(conn){
		if(conn->file)
			fclose(conn->file);
		if(conn->db){
			if(conn->db->rows){
				for(size_t i = 0; i < conn->db->max_rows; i++){
					if(conn->db->rows[i]){
						if(conn->db->rows[i]->name)
							free(conn->db->rows[i]->name);
						if(conn->db->rows[i]->email)
							free(conn->db->rows[i]->email);
						free(conn->db->rows[i]);
					}
				}
				free(conn->db->rows);
			}
			free(conn->db);
		}
		free(conn);
	}
}

void die(struct Connection *conn,  const char *message)
{
	if(errno) {
		perror(message);
	} else {
		printf("ERROR: %s\n", message);
	}
	Database_close(conn);
	exit(1);
}

void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
	int rc = fread(&conn->db->max_rows, sizeof(conn->db->max_rows), 1, conn->file);
	if(rc != 1)
		die(conn,"Failed to load Database(max_rows)");
	rc = fread(&conn->db->max_data, sizeof(conn->db->max_data), 1, conn->file);
	if(rc != 1)
		die(conn,"Failed to load Database(max_data)");
	size_t i = 0;
	conn->db->rows = malloc(sizeof(struct Address*)*conn->db->max_rows);
	for(i = 0; i < conn->db->max_rows; i++){
		conn->db->rows[i] = malloc(sizeof(struct Address));
		rc = fread(&conn->db->rows[i]->id, sizeof(conn->db->rows[i]->id), 1, conn->file);
		if(rc != 1)
			die(conn,"Failed to load Database(Address(id))");
		rc = fread(&conn->db->rows[i]->set, sizeof(conn->db->rows[i]->set), 1, conn->file);
		if(rc != 1)
			die(conn,"Failed to load Database(Address(set))");
		conn->db->rows[i]->name = malloc(conn->db->max_data);
		rc = fread(conn->db->rows[i]->name, sizeof (*conn->db->rows[i]->name) * conn->db->max_data, 1, conn->file);
		if(rc != 1)
			die(conn,"Failed to load Database(Address(name))");
		conn->db->rows[i]->email = malloc(conn->db->max_data);
		rc = fread(conn->db->rows[i]->email, conn->db->max_data, 1, conn->file);
		if(rc != 1)
			die(conn,"Failed to load Database(Address(email))");
	}
}

void Database_set_limits(struct Connection *conn,unsigned long max_rows, unsigned long max_data)
{
	conn->db->max_rows = max_rows;
	conn->db->max_data = max_data; 
}

struct Connection *Database_open(const char *filename, char mode )
{
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn)
		die(conn,"Memory error");
	
	conn->db =  malloc(sizeof(struct Database));
	if(!conn->db)
		die(conn, "Memory error");
	if(mode == 'c'){
		conn->file = fopen(filename, "w");
	} else {
		conn->file = fopen(filename, "r+");
		if(conn->file) {
			Database_load(conn);
		}
	}

	if(!conn->file)
		die(conn,"Failed to open file");

	return conn;
}


void Database_write(struct Connection *conn)
{
	rewind(conn->file);

	int rc = fwrite(&conn->db->max_rows, sizeof(unsigned long),1,conn->file);
	if(rc != 1)
		die(conn,"Failed to write database. max_rows");
	rc = fwrite(&conn->db->max_data, sizeof(unsigned long),1,conn->file);
	if(rc != 1)
		die(conn, "Failed to write database. max_data");
	size_t i = 0;
	for( i = 0; i < conn->db->max_rows; i++){
		struct Address *row = conn->db->rows[i];
		rc = fwrite(&row->id, sizeof(row->id),1, conn->file);
		if(rc != 1)
			die(conn,"Failed to write file Address(id)");
		rc = fwrite(&row->set, sizeof(row->set),1, conn->file);
		if(rc != 1)
			die(conn,"Failed to write file Address(id)");
		rc = fwrite(row->name, conn->db->max_data,1, conn->file);
		if(rc != 1)
			die(conn,"Failed to write file Address(name)");
		rc = fwrite(row->email, conn->db->max_data,1, conn->file);
		if(rc != 1)
			die(conn,"Failed to write file Address(email)");
	}
	rc = fflush(conn->file);
	if( rc == -1)
		die(conn,"Cannot flush database");
}

void Database_create(struct Connection *conn)
{
	int i = 0;
	conn->db->rows = malloc(sizeof(struct Address)*conn->db->max_rows);
	if(conn->db->rows == NULL)
		die(conn,"ERROR: Memory error");
	for(i = 0; i < conn->db->max_rows; i++){
		conn->db->rows[i] = malloc(sizeof(struct Address));
		conn->db->rows[i]->id = i;
		conn->db->rows[i]->set = 0;
		conn->db->rows[i]->name = malloc(conn->db->max_data);
		memset(conn->db->rows[i]->name, ' ',conn->db->max_data);
		if(conn->db->rows[i]->name == NULL)
			die(conn, "ERROR: Memory error");
		conn->db->rows[i]->email = malloc(conn->db->max_data);
		memset(conn->db->rows[i]->email, ' ',conn->db->max_data);
		if(conn->db->rows[i]->email == NULL)
			die(conn, "ERROR: Memory error");
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = conn->db->rows[id];
	if(addr->set)
		die(conn,"Alraedy set, delete it first");
	addr->set = 1;
	char *res = strncpy(addr->name, name, conn->db->max_data);
	if(!res)
		die(conn, "Name copy failed");
        addr->name[ conn->db->max_data] = '\0';	
	res = strncpy(addr->email, email, conn->db->max_data);
	if(!res)
		die(conn,"Email copy failed");
	addr->email[conn->db->max_data] = '\0';
}

void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = conn->db->rows[id];
	if(addr->set){
		Address_print(addr);
	} else {
		die(conn,"ID is not set");
	}
}

void Database_delete(struct Connection *conn, int id){
	//struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id]->set = 0;
}

void Database_list(struct Connection *conn){
	int i = 0;
	struct Database *db = conn->db;

	for( i = 0; i < db->max_rows; i++ ){
		struct Address *cur = db->rows[i];
		if(cur->set){
			Address_print(cur);
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc < 3)
		die(NULL,"Usage: ex17 <dbfile> <action> [action params]");
	char *filename = argv[1];
	char action = argv[2][0];
	struct Connection *conn = Database_open(filename, action);

	int id = 0;

	if(argc > 3) id = atoi(argv[3]);

	switch(action){
		case 'c':
			if(argc != 5) die(conn, "Need max_rows and max_data"); 
			Database_set_limits(conn,atoi(argv[3]), atoi(argv[4]));
			Database_create(conn);
			Database_write(conn);
			break;
		case 'g':
			if(argc != 4)
				die(conn,"Need an id to get");
			Database_get(conn, id);
			break;
		case 's':
			if(argc != 6)
				die(conn,"Need id, name, eamil to set");
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;
		case 'd':
			if(argc != 4)
				die(conn,"Need id to delete");
			Database_delete(conn, id);
			Database_write(conn);
			break;
		case 'l':
			Database_list(conn);
			break;
		default: 
			die(conn,"Invalid action: c=create, g=get, s=set, d=del, l=list");
	}
	Database_close(conn);

	return 0;
}
