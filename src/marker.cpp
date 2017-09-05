
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include<boundingbox_msgs/Boundingbox.h>
#include <nav_msgs/GetPlan.h>
#include <nav_msgs/Path.h>
#include <tf/transform_broadcaster.h>
#include<iostream>
#include <boost/shared_ptr.hpp>



ros::Publisher marker_pub;
 ros::Subscriber marker_sub;
int num=0;
void markercallback(const boundingbox_msgs::Boundingbox& msg){
   
   ros::Rate r(30);
   



              num++;



       
     boost::shared_ptr<visualization_msgs::MarkerArray> ma;
    
     if(ma)
             return ;


      ma=boost::make_shared<visualization_msgs::MarkerArray>();  

 

          
      if(msg.objectName=="person"){

             visualization_msgs::Marker marker;
              marker.header.frame_id="usb_cam";
              marker.header.stamp=ros::Time::now()  ;
              marker.ns="person";
              marker.id=num;
              marker.type = visualization_msgs::Marker::SPHERE;
          
              double width=msg.w;
              double  d=(0.0397*0.5)/(width*0.00007);
                          std::cout<<"11"<<"distance  "<<d<<"\n";
                          std::cout<<"11"<<"width  "<<width<<"\n";
              marker.action=visualization_msgs::Marker::ADD;
              marker.pose.position.x=d*0.3;
              marker.pose.position.y=d*0.7;
              marker.pose.position.z = 0;
              marker.pose.orientation.x = 0.0;
              marker.pose.orientation.y = 0.0;
              marker.pose.orientation.z = 0.0;
              marker.pose.orientation.w = 1.0;
              marker.scale.x = 0.1;
              marker.scale.y = 0.1;
              marker.scale.z = 0.1;
 

              marker.color.r = 0.0f;
              marker.color.g = 1.0f;
              marker.color.b = 0.0f;
              marker.color.a = 1.0;
 
              marker.lifetime = ros::Duration(1);

              ma->markers.push_back(marker);

             
}/*else if(msg.objectName=="chair"){
               for(int num=0;num<5;num++){ 
              visualization_msgs::Marker marker;
         
              marker.header.frame_id="usb_cam";
              marker.header.stamp=ros::Time::now()  ;
              marker.ns="chair";
              marker.id=num;
              double width=msg.w;
              int  d=(0.0397*0.5)/(width*0.00007);
              marker.type = visualization_msgs::Marker::CUBE;

              marker.action=visualization_msgs::Marker::ADD;
              marker.pose.position.x=d*0.4;
              marker.pose.position.y=d*0.2;
              marker.pose.position.z = 0;
              marker.pose.orientation.x = 0.0;
              marker.pose.orientation.y = 0.0;
              marker.pose.orientation.z = 0.0;
              marker.pose.orientation.w = 1.0;
              marker.scale.x = 0.1;
              marker.scale.y = 0.1;
              marker.scale.z = 0.1;
 

              marker.color.r = 1.0f;
              marker.color.g = 0.0f;
              marker.color.b = 0.0f;
              marker.color.a = 1.0;
 
             marker.lifetime = ros::Duration(10);
          
            std::cout<<"22222222"<<"\n";
              ma->markers.push_back(marker);
               // marker_pub.publish(marker);
          

   }      


}*/




marker_pub.publish(ma);

//r.sleep();

 




}


int main(int argc, char** argv){
   ros::init(argc,argv,"base_shapes");
   ros::NodeHandle n;
  // ros::Rate r(1);
   


               
  


marker_pub=n.advertise<visualization_msgs::MarkerArray>("visualization_marker",50);

marker_sub=n.subscribe("/yolo/AAox/usb_cam",50,markercallback);
   

ros::spin();

//r.sleep();



}
