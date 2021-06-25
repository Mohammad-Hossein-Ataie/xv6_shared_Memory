#include "types.h"
#include "stat.h"
#include "user.h"
#include "date.h"   

int main(int argc, char *argv[]){
	if(argc < 2){
		
		printf(2, "You Must Enter One Number!\n");
		exit();
	}
	if(argc == 2){
        struct rtcdate* r = 0;
		// We will use ebx register for storing input number
		int saved_ebx, number = atoi(argv[1]);
		// 
		asm volatile(
			"movl %%ebx, %0;" // saved_ebx = ebx
			"movl %1, %%ebx;" // ebx = number
			: "=r" (saved_ebx)
			: "r"(number)
		);
		printf(1, "User: Set_sleep() Called for number: %d\n" , number);
        date(r);
		//printf(1, "date : %d %d %d\n" , r->hour, r->minute, r->second);

        set_sleep(number);
		asm("movl %0, %%ebx" : : "r"(saved_ebx)); // ebx = saved_ebx -> restore
		date(r);
		//printf(1, "date : %d %d %d\n" , r->hour, r->minute, r->second);
		exit();  	
    }

    printf(1 , "You Must Enter One Number. Bad Read\n");
    exit();
}