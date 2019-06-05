/*Student: Michael Moloney
Class: CSC 4320 MW 2:30-5:30pm
Instructor:Zhisheng Yan
Assignment:Project 1
Due Date: 2/1/2019*/


#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/slab.h>
/*declare birthday struct*/
struct birthday 
{	
	int month;
	int day;
	int year;
	char* name;
	struct list_head list;
};
/**
 * The following defines and initializes a 
 * list_head object named birthday_list
 */
static LIST_HEAD(birthday_list);

int simple_init(void)
{
	
       printk(KERN_INFO "Loading Module\n");
       /* the pointer for memory allocation */
       struct birthday *person_one;
       /* node 1 */
       	person_one = kmalloc(sizeof(*person_one),GFP_KERNEL);
       	person_one->month=8;
       	person_one->day=13;
       	person_one->year=1995;
       	person_one->name="James";
       INIT_LIST_HEAD(&person_one->list);
       /* add the new node */
       list_add_tail(&person_one->list, &birthday_list);

       struct birthday *person_two;
       /* node 2 */
       	person_two = kmalloc(sizeof(*person_two),GFP_KERNEL);
       	person_two->month=3;
       	person_two->day=14;
       	person_two->year=1989;
       	person_two->name="Mike";
       INIT_LIST_HEAD(&person_two->list);
       /* add the new node */
       list_add_tail(&person_two->list, &birthday_list);

       struct birthday *person_three;
       /* node 3 */
       	person_three = kmalloc(sizeof(*person_three),GFP_KERNEL);
       	person_three->month=4;
       	person_three->day=20;
       	person_three->year=1992;
       	person_three->name="Tony";
       INIT_LIST_HEAD(&person_three->list);
       /* add the new node */
       list_add_tail(&person_three->list, &birthday_list);

       struct birthday *person_four;
       /* node 4 */
       	person_four = kmalloc(sizeof(*person_four),GFP_KERNEL);
       	person_four->month=11;
       	person_four->day=2;
       	person_four->year=1973;
       	person_four->name="Sarah";
       INIT_LIST_HEAD(&person_four->list);
       /* add the new node */
       list_add_tail(&person_four->list, &birthday_list);

       struct birthday *person_five;
       /* node 5 */
       	person_five = kmalloc(sizeof(*person_five),GFP_KERNEL);
       	person_five->month=1;
       	person_five->day=31;
       	person_five->year=2000;
       	person_five->name="Michelle";
       INIT_LIST_HEAD(&person_five->list);
       /* add the new node */
       list_add_tail(&person_five->list, &birthday_list);

/*declare the pointers and variables used to determine the oldest student*/
       struct birthday *ptr, *del_pointer, *next;
       int day=32,month=13,year=3000,*pday,*pmonth,*pyear;
       pday=&day;pmonth=&month;pyear=&year;

       list_for_each_entry(ptr,&birthday_list,list){
       	/*on each iteration ptr points to the next birthday struct*/
              /*list the student and their birthday*/
       	printk(KERN_INFO "%s: %d,%d,%d",ptr->name,ptr->month,ptr->day,ptr->year);
/*if the student has a lower year the del_pointer points to them and the
*lowest month,day,year is updated*/
              if(ptr->year<pyear){
                     pyear=ptr->year;
                     pmonth=ptr->month;
                     pday=ptr->day;
                     del_pointer=ptr;
/*if the student has the same year as the lowest then the month and day
are compared. If they are younger, then everything is updated*/      
              }
              else if(ptr->year=pyear)
                     if(ptr->month<=pmonth)
                            if(ptr->day<pday){
                                   pyear=ptr->year;
                                   pmonth=ptr->month;
                                   pday=ptr->day;
                                   del_pointer=ptr;
                            }
       }
/*the youngest student is deleted, and memory freed up.*/
       printk(KERN_INFO "%s is the oldest, so the entry is being deleted"
              ,del_pointer->name);
       list_del(&del_pointer->list);
       kfree(del_pointer);

/*The updated linked list is outputted*/
       list_for_each_entry_safe(ptr,next,&birthday_list,list){
              printk(KERN_INFO "%s: %d,%d,%d",ptr->name,ptr->month,ptr->day,ptr->year);
}
       
       return 0;
}

void simple_exit(void) {
	
	
	printk(KERN_INFO "Removing Module\n");

       struct birthday *ptr, *next;

	list_for_each_entry_safe(ptr,next,&birthday_list,list){
		/*on each iteration ptr points to the next birthday struct*/
              /*linked list entries are deleted one by one.
              memory is freed up.*/
		printk(KERN_INFO "Removing birthday entry of %s",ptr->name);
		list_del(&ptr->list);
		kfree(ptr);
	}
	
	

}

module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel Data Structures");
MODULE_AUTHOR("SGG");
