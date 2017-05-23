#include "Scheduler.h"

using academia::Schedule;
using academia::Scheduler;

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

Schedule Scheduler::PrepareNewSchedule(
    const vector<int> &rooms,
    const map<int, vector<int>> &teacher_courses_assignment,
    const map<int, set<int>> &courses_of_year,
    int n_time_slots
) {
    //
}
