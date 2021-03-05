#include "ros/ros.h"
#include "final_assignment/robot_target.h"
#include <math.h>


// function for generating a random number between 2 numbers [M,N]
int randMToN(int M, int N) 
{ 
	return M + (rand() / ( RAND_MAX / (N-M) ) ) ;
 }


//  given targets on pdf assignment : [(-4,-3);(-4,2);(-4,7);(5,-7);(5,-3);(5,1)]


bool randTarget(final_assignment::robot_target::Request &req, final_assignment::robot_target::Response &res)
{

	int i;	//index position
	int x_coord[] = {-4,-4,-4, 5, 5, 5};  //array for x coordinates
	int y_coord[] = {-3, 2, 7, -7, -3, 1};  //array for y coordinates
	i = randMToN(0,5);
	res.pos_x = x_coord[i]; 
	res.pos_y = y_coord[i];	 
        ROS_INFO("Random target coordinates: [%f] [%f]", res.pos_x, res.pos_y); 
        return true;

}

//Main Function
int main(int argc, char **argv)
{
   // Initialize the node, setup the NodeHandle for handling the communication with the ROS
   // system
   ros::init(argc, argv, "Rand_Server");
   ros::NodeHandle n;
   ros::ServiceServer service= n.advertiseService("/random_target", randTarget);
   ros::spin();

   return 0;
}
