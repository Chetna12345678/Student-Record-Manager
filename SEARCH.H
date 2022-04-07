
void search_enrolno()
{
	  FILE *fp;
	int n,found,i;
	textcolor(11);
	textbackground(BLACK);
	clrscr();
	printf("\t\t\tEnter Enrolment Number : ");
	scanf("%d",&n);


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
	   found=0;
	   i=5;
	while(fread(&s,sizeof(s),1,fp)!=NULL)
	{
	   if(s.enrolno==n)
	   {
		  found=1;
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
	}
	if(found==0)
	{  textcolor(RED+BLINK);
	   printf("\n\t\t\t");
	   cprintf("Not found. Press any key...");
	   fclose(fp);
	   getch();
	   return;
	}
	fclose(fp);
	textcolor(RED+BLINK);
	printf("\n\n\t\t\t\t");
	cprintf("PRESS ANY KEY...");

	getch();
}

//Search by name
void search_name()
  {
	   FILE *fp;
	   int i,found;
	   char n[50];
	   window(1,1,80,25);
	   textbackground(BLACK);
	   textcolor(11);
	   clrscr();
	   printf("\t\t\tEnter student name : ");
	   gets(n);
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
	   found=0;
	   while(fread(&s,sizeof(s),1,fp)!=NULL)
	   {
		 if(strcmpi(n,s.name)==0)
		 {
		  found=1;
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
		  }
		  if(found==0)
	{  textcolor(RED+BLINK);
	   printf("\n\t\t\t");
	   cprintf("Not found. Press any key...");
	   fclose(fp);
	   getch();
	   return;
	}
		   fclose(fp);
		  textcolor(RED+BLINK);
		  printf("\n\n\t\t\t\t");
		  cprintf("PRESS ANY KEY...");

	   getch();
	   }


  //searh by semester
  void search_sem()
{
	FILE *fp;
	int n,found,i;
	textcolor(11);
	textbackground(BLACK);
	clrscr();
	printf("\t\t\tEnter Semester : ");
	scanf("%d",&n);


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
	   found=0;
	   i=5;
	while(fread(&s,sizeof(s),1,fp)!=NULL)
	{
	   if(s.sem==n)
	   {
		  found=1;
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
	}
	if(found==0)
	{  textcolor(RED+BLINK);
	   printf("\n\n\t\t\t");
	   cprintf("Not found. Press any key...");
	   fclose(fp);
	   getch();
	   return;
	}
	fclose(fp);
	textcolor(RED+BLINK);
	printf("\n\n\t\t\t\t");
	cprintf("PRESS ANY KEY...");
	getch();
}


