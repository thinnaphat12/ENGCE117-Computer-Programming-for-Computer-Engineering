#include<stdio.h>
#include<string.h>

struct user{
	char 	name[30] ;
	char 	email[30] ;
	int 	number 	;
}typedef us;

us getdata(us *data, int number, us (*function) ( us *, int)) {
	us keeper ; 
	for ( int i = 0 ; i < number ; i++ ){
		getchar() ;
		printf( "%d's data\nYour name : ",i+1 ) ;
		gets(data[i].name) ;
		printf( "Your email : " ) ;
		gets(data[i].email) ;
		printf( "Your number : " ) ;
		scanf( "%d", &data[i].number ) ;
		printf( "\n" ) ;
	}
	keeper = (*function)( data, number ) ;
	return keeper ;
}

us highnumber(us *data, int number){
	int maxvalue = -9999999 ;
	int position ;
	for ( int i = 0 ; i < number ; i++ ){
		if (data[ i ].number > maxvalue ) {
			position = i ;
			maxvalue = data[ i ].number ;
		}
	}
	return data[ position ] ;
}

int main() {
	us *myuser, pointdata;
	int data ;
	printf( "Input datas number : " ) ;
	scanf( "%d", &data ) ;
	myuser = new us[data] ;
	pointdata = getdata( myuser, data, highnumber ) ;
	printf( "\nThis is your max number's profile'\n" ) ;
	printf( "#%d name : %s\te-mail : %s ", pointdata.number, pointdata.name, pointdata.email ) ;
	return 0 ;
}
