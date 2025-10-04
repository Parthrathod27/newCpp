// 🔰 Problem: Allocate Minimum Number of Pages
// Given an array where each element represents the number of pages in a book,
// and an integer k representing the number of students,
// allocate books so that each student gets a contiguous sequence of books.
// Minimize the maximum number of pages assigned to a student.

// -----------------------------------------------------
// 🧮 BRUTE FORCE APPROACH
// -----------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

class SolutionBrute {
public:
    // ✅ Function to calculate total sum of pages
    int sumArr(vector<int> &arr) {
        int total = 0;
        for (int i = 0; i < arr.size(); i++)
            total += arr[i];
        return total;
    }

    // ✅ Function to count how many students are required 
    // if max pages allowed per student = 'pageLimit'
    int countStudents(vector<int> &arr, int pageLimit) {
        int students = 1;
        int pagesAllocated = 0;

        for (int i = 0; i < arr.size(); i++) {
            // If adding current book exceeds page limit -> allocate to next student
            if (pagesAllocated + arr[i] <= pageLimit) {
                pagesAllocated += arr[i];
            } else {
                students++;
                pagesAllocated = arr[i];
            }
        }
        return students;
    }

    // ✅ Brute force function to find minimum possible max pages
    int findPages(vector<int> &arr, int k) {
        if (arr.size() < k) return -1; // not enough books

        int low = *max_element(arr.begin(), arr.end()); // smallest possible (largest single book)
        int high = sumArr(arr);                         // largest possible (all books to one student)
        int ans = -1;

        // 🔹 Try every possible page limit between [low, high]
        for (int pageLimit = low; pageLimit <= high; pageLimit++) {
            int studentsNeeded = countStudents(arr, pageLimit);

            // If within allowed number of students, this could be our answer
            if (studentsNeeded <= k) {
                ans = pageLimit;
                break; // we found smallest valid limit (since we go increasing)
            }
        }
        return ans;
    }
};



// -----------------------------------------------------
// ⚙️ OPTIMIZED APPROACH (Binary Search)
// -----------------------------------------------------
// 💡 Idea:
// Instead of checking every value from [low, high],
// use binary search to efficiently find the smallest valid page limit.

#include <bits/stdc++.h>
using namespace std;

class SolutionOptimized {
public:
    // ✅ Helper: Calculate total sum of pages
    int sumArr(vector<int> &arr) {
        int total = 0;
        for (int i = 0; i < arr.size(); i++)
            total += arr[i];
        return total;
    }

    // ✅ Helper: Count how many students needed for a given page limit
    int countStudents(vector<int> &arr, int pageLimit) {
        int students = 1;
        int pagesAllocated = 0;

        for (int i = 0; i < arr.size(); i++) {
            if (pagesAllocated + arr[i] <= pageLimit)
                pagesAllocated += arr[i];
            else {
                students++;
                pagesAllocated = arr[i];
            }
        }
        return students;
    }

    // ✅ Main function using Binary Search
    int findPages(vector<int> &arr, int k) {
        if (arr.size() < k) return -1;  // not enough books for students

        int low = *max_element(arr.begin(), arr.end());
        int high = sumArr(arr);
        int result = -1;

        // 🔹 Binary search for minimum valid page limit
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int studentsNeeded = countStudents(arr, mid);

            if (studentsNeeded <= k) {
                result = mid;   // valid, try for smaller page limit
                high = mid - 1;
            } else {
                low = mid + 1;  // too small, need higher limit
            }
        }
        return result == -1 ? low : result;
    }
};                    
           
               
            
            
              
