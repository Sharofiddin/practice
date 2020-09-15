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
	struct Address *rows;
};

struct Connection {
	FILE *file;
	struct Database *db;
};

void Database_close( struct Connection *conn){
	if(conn){
		if(conn->file)
			fclose(conn->file);
		if(conn->db)
			free(conn->db);
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
	int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
	if(rc != 1)
		die(conn,"Failed to load database");
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

	int rc = fwrite(conn->db, sizeof(struct Database),1,conn->file);
	if(rc != 1)
		die(conn,"Failed to write database.");
	rc = fflush(conn->file);
	if( rc == -1)
		die(conn,"Cannot flush database");
}

void Database_create(struct Connection *conn)
{
	int i = 0;
	conn->db->rows = malloc(sizeof(struct Address)*conn->db->max_rows);
	if( conn->db->rows == NULL)
		die(conn,"ERROR: Memory error");
	for(i = 0; i < conn->db->max_rows; i++){
		struct Address addr = {.id = i, .set = 0};
		conn->db->rows[i] = addr;
	}
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = conn->db->rows+id;
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
	struct Address *addr = &conn->db->rows[id];
	if(addr->set){
		Address_print(addr);
	} else {
		die(conn,"ID is not set");
	}
}

void Database_delete(struct Connection *conn, int id){
	struct Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn){
	int i = 0;
	struct Database *db = conn->db;

	for( i = 0; i < db->max_rows; i++ ){
		struct Address *cur = &db->rows[i];
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




	
