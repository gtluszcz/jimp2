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
    //
}

Schedule Schedule::OfRoom(int room_id) const {
    //
}

Schedule Schedule::OfYear(int year) const {
    //
}

vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
    //
}

void Schedule::InsertScheduleItem(const academia::SchedulingItem &item) {
    //
}

size_t Schedule::Size() const {
    //
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

int SchedulingItem::CourseId() { return course_id; }
int SchedulingItem::TeacherId() { return teacher_id; }
int SchedulingItem::RoomId() { return room_id; }
int SchedulingItem::TimeSlot() { return time_slot; }
int SchedulingItem::Year() { return year; }

const vector<int> Scheduler::Rooms() { return rooms; }
const map<int, vector<int>> Scheduler::TeacherCoursesAssignment() { return teacher_courses_assignment; }
const map<int, set<int>> Scheduler::CoursesOfYear() { return courses_of_year; }
int Scheduler::NTimeSlots() { return n_time_slots; }
