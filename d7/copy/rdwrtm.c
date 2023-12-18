int main()
{
	char buf[30];
	int n;
	write(1, "this is written to fd no. 1: \n", 31);
	write(1, "Enter the line of text: ",26);
	n = read(0,buf, 80);

	write(1, "This is the line i read: ",29);
	write(1, buf,n);
}
