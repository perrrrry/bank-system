/*
 * Event.h
 *
 * Class Definition: Event.h to define the private varibles and public mehtod
 *
 *
 * Created on: Februar 26 2019
 * Author: Perry Wu
 */
#pragma once
using namespace std;
#include <cstdio>  // Needed for NULL

typedef enum etype { arrival, departure } EventType;


// Desc:  Represents a simulation event

class Event {
    private:
              int time;   //Events are occurrences that unfold at a specified time
              int length;   // last for a certain duration (length of time).
              EventType type; //handle two types of events: arrival events and departure events.

    public:
        //build a aconstructor
        Event(EventType typ,int t ,int l);
        //create getters
        int Get_time();
        int Get_length();
        EventType Get_type();
        //create setters
        void Set_time(int t);
        void et_length(int l);
        void Set_type(EventType typ);




        // Desc:  Comparators
        bool operator<(const Event &r) const { return this->time > r.time ; };
        bool operator>(const Event &r) const { return this->time < r.time ; };
        bool operator<=(const Event &r) const { return this->time >= r.time ; };
        bool operator>=(const Event &r) const { return this->time <= r.time ; };

}; // Event
