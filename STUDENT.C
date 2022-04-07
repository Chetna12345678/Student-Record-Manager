 #include<conio.h>
 #include<stdio.h>
 #include<string.h>
 #include<stdlib.h>
 #include"data.h"
 #include"search.h"

 void main()
 {
	void add_student();
	void display_student();  //declaration of function
	void delete_student();
	void edit_student();
	void search_student();
	void change_pwd();
	char pass[30],ch,original[30];
	int i,choice;
	FILE *fp;
	window(1,1,80,25);
	textbackground(WHITE);
	clrscr();
	window(10,10,70,20);
	textbackground(BLACK);
	clrscr();
	textcolor(WHITE);
	gotoxy(9,3);
	cprintf("WELCOME TO SCHOOL OF COMPUTER AND SYSTEM SCIENCE");
	gotoxy(16,5);
	textcolor(11);
	cprintf("MASTER OF COMPUTER APPLICATION");
	gotoxy(9,8);
	textcolor(WHITE);
	cprintf("Enter the password:");
	i=0;
	while(1)
	{
	  ch=getch();
	  if(ch==13)  //ASCII code of ENTER key
	  {
		pass[i]='\0';
		break;
	  }
	  pass[i++]=ch;
	  cprintf("*");
	}



	fp=fopen("pwd.dat","r"); //Reading data from the file
	fgets(original,30,fp);
	fclose(fp);
	if(!strcmp(original,pass)==0)
	 {  gotoxy(13,10);
		textcolor(RED+BLINK);
		cprintf("Incorrect Password");
		cprintf("  Enter any key...");
		getch();
		exit(0);
	 }
	else
	{
		window(1,1,80,25);
		textbackground(7);  //7 represents grey color
		clrscr();
		gotoxy(30,3);
		textcolor(BLUE);
		cprintf("STUDENT RECORD MANAGER");
		gotoxy(30,4);
		cprintf("~~~~~~~~~~~~~~~~~~~~~~");
		gotoxy(30,8);
		textcolor(BLACK);
		cprintf("Developed by : Chetna");
		gotoxy(30,9);
		cprintf("~~~~~~~~~~~~~~~~~~~~~");
		gotoxy(10,18);
		cprintf("Please wait ");
		for(i=1;i<=50;i++)
		{
		  cprintf("%c", 220);     //ASCII value of []
		  delay(200);
		}


	  while(1)
	  {
		textbackground(11);
		clrscr();
		window(15,6,65,21);
		textbackground(BLACK);
		clrscr();
		textcolor(11);
		gotoxy(22,2);
		cprintf("MAIN MENU");
		gotoxy(21,3);
		cprintf("-----------");
		textcolor(WHITE);
		gotoxy(10,5);
		cprintf("1. Add new student detail");
		gotoxy(10,6);
		cprintf("2. Delete student detail");
		gotoxy(10,7);
		cprintf("3. Edit student detail");
		gotoxy(10,8);
		cprintf("4. Search using student details");
		gotoxy(10,9);
		cprintf("5. Display list of all students");
		gotoxy(10,10);
		cprintf("6. Change password");
		gotoxy(10,11);
		cprintf("7. Exit");
		gotoxy(10,13);
		textcolor(11);
		cprintf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
		gotoxy(12,15);
		textcolor(11+BLINK);
		cprintf("Enter your choice(1-7)?");
		choice=getche();
		switch(choice)
		{
		   case '1': add_student();
					 break;
		   case '2': delete_student();
					 break;
		   case '3': edit_student();
					 break;
		   case '4': search_student();
					 break;
		   case '5': display_student();
					 break;
		   case '6': change_pwd();
					 break;
		   case '7':exit(0);

		}
   }
	}
	  getch();
 }

	//Search students
	void search_student()
	{
	   char ch;
	   window(1,1,80,25);
	   textbackground(BLACK);
	   textcolor(11);
	   clrscr();

	   gotoxy(35,2);
	   printf("SEARCH OPTIONS");

	   gotoxy(21,3);
	   printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
	   gotoxy(25,5);
	   printf("1. Search by Enrolment Number ");
	   gotoxy(25,6);
	   printf("2. Search by Name");
	   gotoxy(25,7);
	   printf("3. Search by Semester");
	   gotoxy(25,8);
	   printf("5. Back to main menu");
	   gotoxy(21,9);
	   printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
	   textcolor(11+BLINK);
	   gotoxy(22,10);
	   cprintf("\nEnter your choice ? ");
	   ch=getche();
	   switch(ch)
	   {
		  case '1':search_enrolno();
				   break;
		  case '2':search_name();
				   break;
		  case '3':search_sem();
				   break;
		  case '4':return;
		}
	 }

   //change password
	void change_pwd()
	{
	   FILE *fp;
	   char current[30],original[30],newpass[30],confirm[30];
	   window(1,1,80,25);
	   textbackground(BLACK);
	   textcolor(11);
	   clrscr();
	   gotoxy(33,2);
	   printf("CHANGE PASSWORD");
	   gotoxy(20,3);
	   printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
	   gotoxy(21,5);
	   printf("Enter the current password : ");
	   gets(current);

		//Reading password from pwd.dat file
		fp=fopen("pwd.dat","r");
		fgets(original,30,fp);
		fclose(fp);

		if(strcmp(current,original)!=0)
		{
		   gotoxy(23,7);
		   textcolor(RED+BLINK);
		   cprintf("Incorrect password, Press any key...");
		   getch();
		   return;
		}
		gotoxy(21,7);
		printf("Enter new password : ");
		gets(newpass);
		gotoxy(21,9);
		printf("Re-enter password : ");
		gets(confirm);
		if(strcmp(confirm,newpass)!=0)
		{
		  gotoxy(24,11);
		  textcolor(RED+BLINK);
		  cprintf("Not match, Press any key...");
		  getch();
		  return;
		}
		fp=fopen("pwd.dat","w");
		fprintf(fp,"%s",newpass);
		fclose(fp);
		gotoxy(21,11);
		textcolor(RED+BLINK);
		cprintf("Successfully updated, Press any key.... ");
		getch();
	}
	  //Edit student detail
	void edit_student()
	{
	   FILE *fp;
	   int pos,n,found;
	   window(1,1,80,25);
	   textcolor(11);
	   textbackground(BLACK);
	   clrscr();
	   gotoxy(30,2);
	   printf("EDIT STUDENT DETAILS");
	   gotoxy(15,3);
	   printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
	   gotoxy(18,5);
	   printf("Enter the Enrolment number to be edited : ");
	   scanf("%d",&n);
	   fp=fopen("information.dat","r+b");
	   found=0;
	   while(fread(&s,sizeof(s),1,fp)!=NULL)
	   {
		  if(s.enrolno==n)
		  {
			 found=1;
			 gotoxy(20,7);
			 printf("Name of Student  : %s",s.name);
			 gotoxy(20,8);
			 printf("Gender           : %c",s.gender);
			 gotoxy(20,9);
			 printf("Date of Birth    : %d/%d/%d",s.date,s.month,s.year);
			 gotoxy(20,10);
			 printf("E-mail address   : %s",s.email);
			 gotoxy(20,11);
			 printf("Semester         : %d",s.sem);
			 gotoxy(20,12);
			 printf("Phone Number     : %s",s.phone);

			 break;
		  }
	  }
	   if(found==0)
	   {

		 textcolor(RED+BLINK);
		 gotoxy(20,7);
		 cprintf("Enrolment number not found, Press any key...");
		 fclose(fp);
		 getch();
		 return;
	   }

	   gotoxy(30,15);
	   printf("UPDATE STUDENT DETAIL");
	   pos=ftell(fp);
	   fseek(fp,pos-sizeof(s),SEEK_SET);
	   gotoxy(20,17);
	   printf("Enter Name of Student :");
	   scanf("%s",&s.name);     //string input
	   fflush(stdin);
	   gotoxy(20,18);
	   printf("Gender (M/F) :");
	   scanf("%c",&s.gender);
	   fflush(stdin);
	   gotoxy(20,19);
	   printf("Enter Date of Birth (DD/MM/YYYY) :");
	   scanf("%d/%d/%d",&s.date,&s.month,&s.year);
	   fflush(stdin);
	   gotoxy(20,20);
	   printf("Enter Email address :");
	   gets(s.email);
	   fflush(stdin);
	   gotoxy(20,21);
	   printf("Enter Semester (1/2/3/4) :");
	   scanf("%d",&s.sem);
	   fflush(stdin);
	   gotoxy(20,22);
	   printf("Enter Phone No. :");
	   gets(s.phone);
	   fflush(stdin);
	   fwrite(&s,sizeof(s),1,fp);
	   fclose(fp);

	   textcolor(RED+BLINK);
	   gotoxy(22,24);
	   cprintf("Successfully Updated, Press any key... ");
	   getch();
	}
	  //Delete student detail
	void delete_student()
	{  int n,found;
	   char choice;
	   FILE *fp1,*fp2;
	   window(1,1,80,25);
	   textbackground(BLACK);
	   textcolor(11);
	   clrscr();
	   gotoxy(33,2);
	   printf("DELETE STUDENT DETAILS");
	   gotoxy(19,3);
	   printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
	   gotoxy(20,5);
	   printf("Enter Enrolment Number to be deleted : ");
	   scanf("%d",&n);
	   fp1=fopen("information.dat","rb");
	   found=0;
	   while(fread(&s,sizeof(s),1,fp1)!=NULL)
	   {
		  if(s.enrolno==n)
		  {  gotoxy(25,7);
			 printf("Enrolment Number : %d",s.enrolno);
			 gotoxy(25,8);
			 printf("Name of Student  : %s",s.name);
			 gotoxy(25,9);
			 printf("Gender           : %c",s.gender);
			 gotoxy(25,10);
			 printf("Date of Birth    : %d/%d/%d",s.date,s.month,s.year);
			 gotoxy(25,11);
			 printf("E-mail address   : %s",s.email);
			 gotoxy(25,12);
			 printf("Semester         : %d",s.sem);
			 gotoxy(25,13);
			 printf("Phone Number     : %s",s.phone);
			 gotoxy(19,14);
			 printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");

			 found=1;
			 break;

		  }
	}
	if(found==0)
	{
	   textcolor(RED+BLINK);
	   gotoxy(23,7);
	   cprintf("Enrolment Number not found,Press any key...");
	   getch();
	   fclose(fp1);
	   return;
	}
	gotoxy(20,17);
	printf("Do you want to delete this student detail?(Y/N) : ");
	choice=getche();
	if(choice=='y' || choice=='Y')
	{
	rewind(fp1); //cursor moves to the top of info file
	fp2=fopen("temp.dat","wb"); //write in binary file
	while(fread(&s,sizeof(s),1,fp1)!=NULL)
	{
	   if(s.enrolno!=n)
		 fwrite(&s,sizeof(s),1,fp2);
	}
	fclose(fp1);
	fclose(fp2);
	remove("information.dat");
	rename("temp.dat","information.dat");
	textcolor(RED+BLINK);
	gotoxy(25,19);
	cprintf("Successfully deleted,Press any key....");
	getch();
 }
 }
	 //insert student
	void add_student()
	{

	   FILE *fp;
	   int n,found;
	   window(1,1,80,25);
	   textbackground(BLACK);
	   textcolor(11);
	   clrscr();
	   gotoxy(32,2);
	   printf("ADD NEW STUDENT DETAIL\n");
	   gotoxy(21,3);
	   printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
	   gotoxy(25,5);
	   fflush(stdin);
	   textcolor(11);
	   printf("Enter Enrolment Number :");
	   scanf("%d",&s.enrolno);
	   gotoxy(25,6);
	   fflush(stdin);
	   printf("Enter Name of Student :");
	   gets(s.name);
	   gotoxy(25,7);                     //string input
	   fflush(stdin);
	   printf("Gender (M/F) :");
	   scanf("%c",&s.gender);
	   gotoxy(25,8);
	   fflush(stdin);
	   printf("Enter Date of Birth (DD/MM/YYYY) :");
	   scanf("%d/%d/%d",&s.date,&s.month,&s.year);
	   gotoxy(25,9);
	   fflush(stdin);
	   printf("Enter Email address :");
	   gets(s.email);
	   gotoxy(25,10);
	   fflush(stdin);
	   printf("Enter Semester (1/2/3/4) :");
	   scanf("%d",&s.sem);
	   gotoxy(25,11);
	   fflush(stdin);
	   printf("Enter Phone No. :");
	   gets(s.phone);
	   gotoxy(25,12);
	   fflush(stdin);
	   fp=fopen("information.dat","ab");  //append binary form
	   fwrite(&s,sizeof(s),1,fp);
	   fclose(fp);
	   gotoxy(21,13);
	   printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
	   gotoxy(25,15);
	   textcolor(RED+BLINK);
	   cprintf("Successfully saved, Press any key...");
	   getch();

  }

  void display_student()
  {
	   FILE *fp;
	   int i;
	   window(1,1,80,25);
	   textbackground(BLACK);
	   textcolor(11);
	   clrscr();
	   gotoxy(29,1);
	   printf("DISPLAY ALL STUDENT DETAILS\n");
	   for(i=1;i<=80;i++)
	   printf("-");
	   gotoxy(3,3);
	   printf("ENRNO");
	   gotoxy(11,3);
	   printf("NAME");
	   gotoxy(22,3);
	   printf("GENDER");
	   gotoxy(32,3);
	   printf("DOB");
	   gotoxy(43,3);
	   printf("EMAIL");
	   gotoxy(62,3);
	   printf("SEM");
	   gotoxy(69,3);
	   printf("PHONE NO");

	   printf("\n");
	   for(i=1;i<=80;i++)
	   printf("-");
	   fp=fopen("information.dat","rb"); //read data in binary form
	   i=5;
	   while(fread(&s,sizeof(s),1,fp)!=NULL)
	   {
		  gotoxy(3,i);
		  printf("%d",s.enrolno);
		  gotoxy(11,i);
		  printf("%s",s.name);
		  gotoxy(22,i);
		  printf("%c",s.gender);
		  gotoxy(32,i);
		  printf("%d/%d/%d",s.date,s.month,s.year);
		  gotoxy(43,i);
		  printf("%s",s.email);
		  gotoxy(62,i);
		  printf("%d",s.sem);
		   gotoxy(69,i);
		  printf("%s",s.phone);
		  i++;  //row change


		  }
		  fclose(fp);
		  textcolor(RED+BLINK);
		  printf("\n\n");
		  printf("\t\t\t\t");
		  cprintf("PRESS ANY KEY...");

	   getch();
	   }