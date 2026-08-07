#pragma once

using namespace std;
#include <string>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

namespace solution {
vector<int> twoSum(vector<int> &nums, int target);
ListNode *addTwoNumber(ListNode *l1, ListNode *l2);
bool isPalindrome(int x);
bool hasCycle(ListNode *head);
vector<int> topKFrequent(vector<int> &nums, int k);
int minimumEffort(vector<vector<int>> &tasks);
int minMoves(vector<int> &nums, int limit);
int findMin(vector<int> &nums);
bool canReach(vector<int> &arr, int start);
bool canReach(string s, int minJump, int maxJump);
int minJumps(vector<int> &arr);
int getCommon(vector<int> &nums1, vector<int> &nums2);
vector<int> leftRightDifference(vector<int> &nums);
vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B);
int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2);
int search(vector<int> &nums, int target);
bool check(vector<int> &nums);
int maxJumps(vector<int> &arr, int d);
int earliestFinishTime(vector<int> &landStartTime, vector<int> &landDuration, vector<int> &waterStartTime,
                       vector<int> &waterDuration);
int numberOfSpecialChars(string word);
int numberOfSpecialCharsII(string word);
int totalWaviness(int num1, int num2);
}; // namespace solution

namespace quests {
namespace array1 {
vector<int> getConcatenation(vector<int> &nums);
vector<int> shuffle(vector<int> &nums, int n);
int findMaxConsecutivesOnes(vector<int> &nums);
vector<int> findErrorNums(vector<int> &nums);
}; // namespace array1

namespace array2 {
vector<int> findDisappeardNumbers(vector<int> &nums);
};

namespace stack1 {
int evalRPN(vector<string> &tokens);
vector<int> exclusiveTime(int n, vector<string> &logs);
}; // namespace stack1

namespace monotonic1 {
vector<int> finalPrices(vector<int> &prices);
vector<int> dailyTemperatures(vector<int> &temperatures);
int largestRectangleArea(vector<int> &heights);
}; // namespace monotonic1
}; // namespace quests

namespace plans {
namespace LeetCode75 {

string reverseWords(string s);
vector<int> productExceptSelf(vector<int> &nums);
}; // namespace LeetCode75
}; // namespace plans