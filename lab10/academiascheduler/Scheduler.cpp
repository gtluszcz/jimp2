#include "Scheduler.h"

using academia::SchedulingItem;
using academia::Schedule;
using academia::Scheduler;

/**
 * SchedulingItem
 */

SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) : course_id(course_id), teacher_id(teacher_id), room_id(room_id), time_slot(time_slot), year(year) {
    //
}

/**
 * Schedule
 */

Schedule Schedule::OfTeacher(int teacher_id) const {
    Schedule tmp;
    for (auto & el: schedule_items){
        if (el->TeacherId() == teacher_id){
            tmp.InsertScheduleItem(*el);
        }
    }
    return tmp;
}

Schedule Schedule::OfRoom(int room_id) const {
    Schedule tmp;
    for (auto & el: schedule_items){
        if (el->RoomId() == room_id){
            tmp.InsertScheduleItem(*el);
        }
    }
    return tmp;
}

Schedule Schedule::OfYear(int year) const {
    Schedule tmp;
    for (auto & el: schedule_items){
        if (el->Year() == year){
            tmp.InsertScheduleItem(*el);
        }
    }
    return tmp;
}

vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
    vector<int> free_slots;
    vector<int> bad_slots;
    for (auto & el: schedule_items){
        bad_slots.push_back(el->TimeSlot());
    }
    for (int i = 1; i <= n_time_slots; ++i) {
        if (std::find(bad_slots.begin(),bad_slots.end(),i) != bad_slots.end()){

        }
        else{
        free_slots.push_back(i);
        }
    }
    return free_slots;
}

void Schedule::InsertScheduleItem(const SchedulingItem &item) {
    schedule_items.push_back(&item);
}

size_t Schedule::Size() const {
    return schedule_items.size();
}
const SchedulingItem & Schedule::operator[](int id) const {
    return *(schedule_items[id]);
}

/**
 * Scheduler
 */

Schedule Scheduler::PrepareNewSchedule(
    const vector<int> &rooms,
    const map<int, vector<int>> &teacher_courses_assignment,
    const map<int, set<int>> &courses_of_year,
    int n_time_slots
) {
    //
}

/**
 * Getters
 */

const int SchedulingItem::CourseId() const  { return course_id; }
const int SchedulingItem::TeacherId() const  { return teacher_id; }
const int SchedulingItem::RoomId() const { return room_id; }
const int SchedulingItem::TimeSlot() const  { return time_slot; }
const int SchedulingItem::Year() const  { return year; }

const vector<int> Scheduler::Rooms() { return rooms; }
const map<int, vector<int>> Scheduler::TeacherCoursesAssignment() { return teacher_courses_assignment; }
const map<int, set<int>> Scheduler::CoursesOfYear() { return courses_of_year; }
int Scheduler::NTimeSlots() { return n_time_slots; }
