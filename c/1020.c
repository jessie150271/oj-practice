#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	long long int num_int;
	char input[999];
	char *take;
	char *take_;
	char *take_num;
	int k,num_point,len,token;
	while (gets(input)!=NULL)
	{
		int test = 0, time = 0, test_int = 0;
		take = strtok(input, " ");
		take_ = take;
		take=strtok(NULL, " ");
		k = atoi(take);
		if (k == 0)
		{
			for (int i = 0; i<strlen(take_); i++)
			{
				if(take_[i]=='.'){test_int=1;break;}
			}
		}
		if (test_int == 0)
		{
			num_int = atoll(take_);
			printf("%lld\n", num_int);
			continue;
		}

		take_num = strtok(take_, ".");
		num_int = atoll(take_num);
		if (num_int<0) { test = 1; }

		take_num = strtok(NULL, ".");
		len =strlen(take_num);
		
		for (int i = 0;; i++)
		{
			if(take_num[i]=='0'){time+=1;}
			else
				break;
		}
		num_point = atoi(take_num);
		token=pow(10,len-k-1);
		num_point/=token;

		int point;
		point=num_point%10;
		if (num_point<5)
		{
			printf("%lld\n", num_int);
			continue;
		}
		else if (num_point>=5&&num_point<10)
		{
			if(test==0&&time==0){printf("%lld\n",num_int+1);}
			else if(test==1&&time==0){printf("%lld\n",num_int-1);}
			else
			{
				printf("%lld.",num_int);
				for (time; time > 1; time--){printf("0");}
				printf("1\n");
			}
			continue;
		}
		else if (point < 5)
		{
			num_point /= 10;
			for(;num_point%10==0&&num_point>0; num_point/=10);
			if(time==0){printf("%lld.%d\n",num_int,num_point);}
			else
			{
				printf("%lld.",num_int);
				for (time; time > 0; time--){printf("0");}
				printf("%d\n", num_point);
			}
			continue;
		}
		else if (point >= 5)
		{
			num_point /= 10;
			int i = 0;
			for(int j=num_point; j>0;j/=10){i++;}
			num_point += 1;
			for(int q=num_point; q>0;q/=10){i--;}
			for(; num_point%10==0&&num_point>0; num_point/=10);

			if(time==0&&i==0){printf("%lld.%d\n",num_int,num_point);}
			else if(time==0&&i!=0)
			{
				if(test==0){printf("%lld\n",num_int+1);}
				else{printf("%lld\n",num_int-1);}
			}
			else
			{
				printf("%lld.",num_int);
				for(time;time>1;time--){printf("0"); }
				printf("1\n");
			}
			continue;
		}

	}
	return 0;
}