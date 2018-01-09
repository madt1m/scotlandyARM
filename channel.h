connection openConnection();
closeConnection(connection conn_channel);
char* readFrom(connection conn_channel);
writeTo(connection conn_channel, char* message);