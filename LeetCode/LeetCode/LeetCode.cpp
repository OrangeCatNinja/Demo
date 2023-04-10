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

	//6. N 字形变换
	std::string convert(std::string s, int numRows) {
		if (s.length() <= 2 || s.length() <= numRows || numRows <= 1)
			return s;

		std::vector<std::string> vecStr(numRows);
		int nIndex = 0;
		int nOffset = 2 * numRows - 2;
		for(int nCount = 1; nCount <= s.length() / nOffset + 1; ++nCount)
		{
			std::string strSub = s.substr(nIndex, nOffset);
			for (int i = 0; i < numRows; ++i)
			{
				if (i < strSub.length())
				{
					vecStr[i] += strSub[i];
					int nSubOffset = i + 2 * (numRows - 1 - i);
					if (nSubOffset < strSub.length() && i != numRows - 1)
						vecStr[i] += strSub[nSubOffset];
				}
			}

			if (s.length() - (nCount + 1) * nOffset >= 0)
				nIndex += nOffset;
			else
				nOffset = s.length() - nCount * nOffset;
		}

		std::string strRes;
		for (int i = 0; i < numRows; ++i)
		{
			strRes += vecStr[i];
		}
		return strRes;
	}

	//11. 盛最多水的容器
	int maxArea(std::vector<int>& height) {
		if (height.size() < 2)
			return 0;

		int nIndex = 0;
		int nLast = height.size() - 1;

		int nMaxArea = 0;

		while (nIndex < nLast)
		{
			int nHeight = height[nIndex] > height[nLast] ? height[nLast] : height[nIndex];
			int nArea = (nLast - nIndex) * nHeight;
			if (nMaxArea < nArea)
				nMaxArea = nArea;

			if (height[nIndex] < height[nLast])
				++nIndex;
			else
				--nLast;
		}

		return nMaxArea;
	}

	//15. 三数之和
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		std::vector<std::vector<int>> res;
		
		std::sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > 0)
				break;

			if(i > 0 && nums[i] == nums[i - 1])
				continue;

			int nFirst = i + 1;
			int nLast = nums.size() - 1;

			while (nFirst < nLast)
			{
				if (nFirst > i + 1 && nums[nFirst] == nums[nFirst - 1])
				{
					++nFirst;
					continue;
				}
				if (nLast < nums.size() - 1 && nums[nLast] == nums[nLast + 1])
				{
					--nLast;
					continue;
				}

				int nSum = nums[i] + nums[nFirst] + nums[nLast];
				if (nSum == 0)
				{
					res.push_back({ nums[i], nums[nFirst++], nums[nLast--] });
				}
				else if(nSum > 0)
				{
					--nLast;
				}
				else if (nSum < 0)
				{
					++nFirst;
				}
			}
		}


		return res;
	}

	//17. 电话号码的字母组合
	std::vector<std::string> letterCombinations(std::string digits) {
		typedef std::vector<char> Alphabet;
		const std::unordered_map<int, Alphabet> numCharMap = {
			std::pair<int, Alphabet>(2,{'a', 'b', 'c'}),
			std::pair<int, Alphabet>(3,{'d', 'e', 'f'}),
			std::pair<int, Alphabet>(4,{'g', 'h', 'i'}),
			std::pair<int, Alphabet>(5,{'j', 'k', 'l'}),
			std::pair<int, Alphabet>(6,{'m', 'n', 'o'}),
			std::pair<int, Alphabet>(7,{'p', 'q', 'r', 's'}),
			std::pair<int, Alphabet>(8,{'t', 'u', 'v'}),
			std::pair<int, Alphabet>(9,{'w', 'x', 'y', 'z'})
		};

		int nNum = 1;
		for (int nIndex = 0; nIndex < digits.size(); ++nIndex)
		{
			std::unordered_map<int, Alphabet>::const_iterator numCharItr = numCharMap.find(digits[nIndex] - '0');
			if(numCharItr == numCharMap.end())
				continue;

			nNum *= numCharItr->second.size();
		}
		std::vector<std::string> vecRes(nNum);

		for (int nIndex = 0; nIndex < digits.size(); ++nIndex)
		{
			std::unordered_map<int, Alphabet>::const_iterator numCharItr = numCharMap.find(digits[nIndex] - '0');
			if (numCharItr == numCharMap.end())
				continue;

			Alphabet::const_iterator charItr = numCharItr->second.begin();

			const Alphabet& charVec = numCharItr->second;
			for (int i = 0; i < nNum; ++i)
			{
				int nTempIndex = i % charVec.size();
				if(i < 3)
				vecRes[i] += charVec[i % charVec.size()];
			}
		}

		return vecRes;
	}
};

int main()
{
	Solution solt;



	return 0;
}
