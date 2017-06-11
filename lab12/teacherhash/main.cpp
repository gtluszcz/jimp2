#include "TeacherHash.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
using namespace academia;

void CanCreateTeacherIdCastableToInt() {
    TeacherId id (1002);
    int casted_id = id;
    cout << (1002 == casted_id);
    cout << (1002 == id);
}

void CanCompareDifferentTeacherIdsAndReturnsFalse() {
    TeacherId id1 (300);
    TeacherId id2 (347);
    cout << (id1 != id2);
}

void CanCompareSameTeacherIdsAndReturnsTrue() {
    TeacherId id1 (612);
    TeacherId id2 (612);
    cout << (id1 == id2);
}

void CanCreateTeacherWithSpecifiedFields() {
    Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
    cout << ((TeacherId(1002)) == s1.Id());
    cout << ("Alozjzy"s == s1.Name());
    cout << ("Katedra Informatyki"s == s1.Department());
}

void CanCompareSameTeachersAndReturnsTrue() {
    Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
    Teacher s2 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
    cout << (s1 == s2);
}

//void CanCalculateHashOfTeacherUsingStructWithRedefinedFunctionCallOperator() {
//    Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
//    const TeacherHash hash {};
//    size_t hash_value = hash(s1);
//    cout << (0 != hash_value);
//    cout << (0 != hash(s1));
//}
//
//void EveryHashCalculationGiveSameResult() {
//    Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
//    const TeacherHash hash {};
//    size_t hash_value = hash(s1);
//    cout << (0 != hash_value);
//
//    size_t hash_value2 = hash(s1);
//    cout << (hash_value2 == hash_value);
//}
//
//void SameTeachersHasEqualHashes() {
//    Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
//    Teacher s2 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
//    const TeacherHash hash {};
//    cout << (s1 == s2);
//    cout << (hash(s1) == hash(s2));
//    //and again the same result
//    cout << (hash(s1) == hash(s2));
//}
//
//void DifferentTeachersHasUsuallyHaveDifferentHashes() {
//    Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
//    Teacher s2 = Teacher (TeacherId (1003), "Euzebiusz", "Katedra Automatyki");
//    const TeacherHash hash {};
//    cout << (s1 != s2);
//    cout << (hash(s1) != hash(s2));
//}
//
//void AlmostEqualTeachersHasUsuallyHaveDifferentHashesToo() {
//    Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
//    Teacher s2 = Teacher (TeacherId (1002), "Alozjzy", "Katedra InFormatyki");
//    Teacher s3 = Teacher (TeacherId (1003), "Alozjzy", "Katedra Informatyki");
//    Teacher s4 = Teacher (TeacherId (1002), "alozjzy", "Katedra Informatyki");
//    const TeacherHash hash {};
//    cout << (s1 != s2);
//    cout << (s1 != s3);
//    cout << (s1 != s4);
//    cout << (s2 != s3);
//    cout << (s2 != s4);
//    cout << (s3 != s4);
//    cout << (hash(s1) != hash(s2));
//    cout << (hash(s1) != hash(s3));
//    cout << (hash(s1) != hash(s4));
//    cout << (hash(s2) != hash(s3));
//    cout << (hash(s2) != hash(s4));
//    cout << (hash(s3) != hash(s4));
//}
//
//void CanInsertTeachersAsKeysIntoUnorderedMap() {
//    Teacher s1 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
//    Teacher s2 = Teacher (TeacherId (1002), "Alozjzy", "Katedra Informatyki");
//    Teacher s3 = Teacher (TeacherId (1017), "Klaudiusz", "Katedra Elektroniki");
//    const TeacherHash hash {};
//    std::unordered_map<Teacher, int, TeacherHash> m;
//    m.emplace(s1, 100'000'000);
//    m.emplace(s3, 98);
//
//    cout << (2 == m.size());
//    cout << (100'000'000 == m[s1]);
//    cout << (100'000'000 == m[s2]);
//    cout << (98 == m[s3]);
//}


int main() {
    CanCreateTeacherIdCastableToInt();
    CanCompareDifferentTeacherIdsAndReturnsFalse();
    CanCompareSameTeacherIdsAndReturnsTrue();
    CanCreateTeacherWithSpecifiedFields();
    CanCompareSameTeachersAndReturnsTrue();
//    CanCalculateHashOfTeacherUsingStructWithRedefinedFunctionCallOperator();
//    EveryHashCalculationGiveSameResult();
//    SameTeachersHasEqualHashes();
//    DifferentTeachersHasUsuallyHaveDifferentHashes();
//    AlmostEqualTeachersHasUsuallyHaveDifferentHashesToo();
//    CanInsertTeachersAsKeysIntoUnorderedMap();
}
