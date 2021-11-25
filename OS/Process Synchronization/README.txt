1. To run this program you must compile it useing this line in linux:
	"gcc ap3.c -lpthread -lrt -o ap -w"
2. To run it you may follow the command and insert you own integers of your choosing"
	"./ap <The number of producer threads> <The number of consumer threads> <The number of items that should be produced by all the producer threads collectively before they are done>
	Example:
	"./ap 2 2 2"