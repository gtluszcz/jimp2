/**
 * Please note that on our machines, running MacOS, not even one test compiles.
 * Because of that we are very limited and have done this exercise with
 * intuition and following compiler errors only.
 */

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <map>
#include <set>

using std::vector;
using std::map;
using std::set;

namespace academia {
    class SchedulingItem {
    public:
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);
        const int CourseId() const;
        const int TeacherId() const;
        const int RoomId() const;
        const int TimeSlot() const;
        const int Year() const;
        void SetRoomId(int room_id);
        void SetTimeSlot(int time_slot);

    private:
        int course_id;
        int room_id;
        int time_slot;
        int teacher_id;
        int year;
    };

    class Schedule {
    public:
        Schedule OfTeacher(int teacher_id) const;
        Schedule OfRoom(int room_id) const;
        Schedule OfYear(int year) const;
        vector<int> AvailableTimeSlots(int n_time_slots) const;
        void InsertScheduleItem(const SchedulingItem &item);
        size_t Size() const;
        const SchedulingItem & operator[](int id) const;

    private:
        vector<const SchedulingItem *> schedule_items;
    };

    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(
            const vector<int> &rooms,
            const map<int, vector<int>> &teacher_courses_assignment,
            const map<int, set<int>> &courses_of_year,
            int n_time_slots
        );
    };

    class NoViableSolutionFound {};

    class GreedyScheduler : public Scheduler {
    public:
        Schedule PrepareNewSchedule(
            const vector<int> &rooms,
            const map<int, vector<int>> &teacher_courses_assignment,
            const map<int, set<int>> &courses_of_year,
            int n_time_slots
        );
    };
}

#endif
