

using namespace std;
#include <cstdio>  // Needed for NULL

#include "Event.h"
/*
 * Event.cpp
 *
 * Class Definition: Event.cpp to specifiy the mehtod in details
 *
 *
 * Created on: Februar 26 2019
 * Author: Perry Wu
 */



//build a constructor with type as typ and time as t and length as l
Event::Event(EventType typ,int t ,int l){
  //initialize the parameter
      type = typ; //type as typ
      time = t; //time as t
      length = l;//length as l
}


//get time
int Event::Get_time(){
  return time;
}

//get length
int Event::Get_length(){
return length;
}

//get type
EventType Event::Get_type(){
  return type;
}

//setting the time
void Event::Set_time(int t){
  time = t;
}

//setting the time
void Event::Set_length(int l){
  length = l;
}

//setting the time
void Event::Set_type(EventType typ){
  type = typ;
}
