#include "Scheduler.h"
#include <utility>
#include <algorithm>

using academia::SchedulingItem;
using academia::Schedule;
using academia::Scheduler;
using std::pair;
using std::count;
using std::find;

/**
 * SchedulingItem
 */

SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year)
    : course_id(course_id), teacher_id(teacher_id), room_id(room_id), time_slot(time_slot), year(year) {}

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

    for (auto & el : schedule_items){
        bad_slots.push_back(el->TimeSlot());
    }

    for (int i = 1; i <= n_time_slots; ++i) {
        if (find(bad_slots.begin(), bad_slots.end(), i) == bad_slots.end()){
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

Schedule academia::GreedyScheduler::PrepareNewSchedule(
    const vector<int> &rooms,
    const map<int, vector<int>> &teacher_courses_assignment,
    const map<int, set<int>> &courses_of_year,
    int n_time_slots
) {
    vector<SchedulingItem> scheduling_items;
    int number_of_courses;

    for (auto year_courses : courses_of_year) {
        for (auto course : year_courses.second) {
            number_of_courses = 0;

            for (auto teacher_courses : teacher_courses_assignment) {
                number_of_courses += count(teacher_courses.second.begin(), teacher_courses.second.end(), course);
            }

            if (number_of_courses > n_time_slots) {
                throw NoViableSolutionFound();
            }
        }
    }

    for (auto teacher_course : teacher_courses_assignment) {
        for (auto course : teacher_course.second) {
            for (auto year_course : courses_of_year) {
                if (year_course.second.find(course) != year_course.second.end()) {
                    scheduling_items.push_back(SchedulingItem(course, teacher_course.first, 0, 0, year_course.first));
                }
            }
        }
    }

    if (scheduling_items.size() > rooms.size() * n_time_slots) {
        throw NoViableSolutionFound();
    }

    int i = 0;
    for (auto room : rooms) {
        for (int time_slot = 1; time_slot <= n_time_slots; time_slot++){
            if (i < scheduling_items.size()) {
                scheduling_items[i].time_slot = time_slot;
                scheduling_items[i].room_id = room;
            }
            i++;
        }
    }

    Schedule tmp;
    for (auto item : scheduling_items) {
        tmp.InsertScheduleItem(SchedulingItem {item.course_id, item.teacher_id, item.room_id, item.time_slot, item.year});
    }
    return tmp;
}

/**
 * Getters
 */

const int SchedulingItem::CourseId() const { return course_id; }
const int SchedulingItem::TeacherId() const { return teacher_id; }
const int SchedulingItem::RoomId() const { return room_id; }
const int SchedulingItem::TimeSlot() const { return time_slot; }
const int SchedulingItem::Year() const { return year; }
