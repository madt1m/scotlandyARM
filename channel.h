
connection openConnection();
closeConnection(connection conn_channel);

/*
* readFrom takes as input the connection to read from, and a buffer to store the 
* read bytes. It returns the number of bytes read.
*/
int readFrom(connection conn_channel, char* buffer);
/*
* writeTo takes the connection to write to, and the message to write.
* It returns the number of bytes written.
*/
int writeTo(connection conn_channel, char* message);