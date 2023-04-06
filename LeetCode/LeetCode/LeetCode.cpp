// Demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "include.h"

class Solution {
public:

	//2.两数相加
	struct ListNode
	{
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
	};
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		const ListNode* pLine1 = l1;
		const ListNode* pLine2 = l2;
		ListNode* pRes = new ListNode();
		ListNode* pLine3 = pRes;

		int nSumNext = 0;
		while (pLine1 || pLine2 || nSumNext)
		{
			int nSum = nSumNext;
			if (pLine1)
				nSum += pLine1->val;
			if (pLine2)
				nSum += pLine2->val;

			int nData = nSum % 10;
			nSumNext = nSum / 10;

			ListNode* pTemp = new ListNode(nData);
			pLine3->next = pTemp;
			pLine3 = pLine3->next;

			if(pLine1)
				pLine1 = pLine1->next;
			if(pLine2)
				pLine2 = pLine2->next;
		}

		pRes = pRes->next;
		return pRes;
	}

	//1.两数之和
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> vec{0, 0};
		std::unordered_multimap<int, int> hashNums;

		for (int i = 0; i < nums.size(); ++i)
		{
			hashNums.insert(std::pair<int, int>(nums[i], i));
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			int nEle = nums[i];

			int nSecondNum = target - nEle;
			std::unordered_map<int, int>::const_iterator itr = hashNums.find(nSecondNum);
			if (itr != hashNums.end() && itr->second != i)
			{
				vec[0] = i;
				vec[1] = itr->second;
				break;
			}
		}

		return vec;
	}

	//2367.算数三元组的数目
	int arithmeticTriplets(std::vector<int>& nums, int diff) {
		int nNum = 0;

		std::unordered_map<int, int> mapValueIndex;
		for (int i = 0; i < nums.size(); ++i)
		{
			mapValueIndex[nums[i]] = i;
		}

		for (int i = 0; i < nums.size(); ++i)
		{
			std::unordered_map<int, int>::const_iterator itrSecond = mapValueIndex.find(nums[i] + diff);
			std::unordered_map<int, int>::const_iterator itrThird = mapValueIndex.find(nums[i] + diff + diff);

			if (itrSecond != mapValueIndex.end()
				&& itrThird != mapValueIndex.end()
				&& itrSecond->second > i
				&& itrThird->second > itrSecond->second)
			{
				++nNum;
			}
		}

		return nNum;
	}

	//3.无重复字符的最长子串
	int lengthOfLongestSubstring(std::string s) {
		if (s.length() <= 0)
			return 0;

		int nCount = 0;
		int nIndex = 0;
		int nLastIndex = 0;

		std::unordered_set<char> setChar;
		setChar.insert(s.at(nLastIndex++));

		while (nLastIndex < s.length())
		{
			if (setChar.count(s.at(nLastIndex)) != 0)
			{
				nCount = setChar.size() > nCount ? setChar.size() : nCount;
				do 
				{
					setChar.erase(s.at(nIndex++));
				} while (setChar.count(s.at(nLastIndex)));
			}
			setChar.insert(s.at(nLastIndex++));
		}

		nCount = setChar.size() > nCount ? setChar.size() : nCount;
		return nCount;
	}

	//4.寻找两个正序数组的中位数
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		return 0;
	}

	//5. 最长回文子串
	std::string longestPalindrome(std::string s) {
		int nIndex = 0;
		int nLast = s.length() - 1;
		std::pair<int, int> maxLength(0, 0);

		if (s.length() <= 1)
			return s;

		while (nIndex <= nLast
			&& nLast < s.length())
		{
			nLast = s.find_last_of(s[nIndex], nLast);
			if (nLast <= nIndex)
			{
				nIndex++;
				nLast = s.length() - 1;
				continue;
			}

			int nTempIndex = nIndex;
			int nTempLast = nLast;
			bool bSucess = true;
			while (nTempIndex <= nTempLast)
			{
				if (s[++nTempIndex] != s[--nTempLast])
				{
					bSucess = false;
					break;
				}
			}

			if (bSucess)
			{
				if (maxLength.second - maxLength.first < nLast - nIndex)
				{
					maxLength.first = nIndex;
					maxLength.second = nLast;
					++nIndex;
					nLast = s.length() - 1;
				}
				else
				{
					++nIndex;
					nLast = s.length() - 1;
				}
			}
			else
			{
				--nLast;
			}
		}

		return s.substr(maxLength.first, maxLength.second - maxLength.first + 1);
	}
};

int main()
{
	Solution solt;
	
	std::cout << solt.longestPalindrome("cbbd").c_str() << std::endl;

	return 0;
}
