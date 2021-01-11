#include "TagsManager.h"
#include "MyException.h"
#include <algorithm>
#include <queue>
#include <string>
int TagsManager::identifyTag(const Tag& input) const
{
	int tag_count = tag_masks.size();

	for (size_t tag_mask = 0; tag_mask < tag_count; tag_mask++)
	{
		if (tag_masks[tag_mask].hasSameName(input.getName()))
			return tag_mask;
	}

	return -1;
}

void TagsManager::mapInc(float arg, std::vector<float>& numbers, int from, int to) {
	std::vector<float>::iterator end = numbers.begin() + to;
	for (std::vector<float>::iterator i = numbers.begin() + from; i <= end; i++)
	{
		*i += arg;
	}
}
void TagsManager::mapMlt(float arg, std::vector<float>& numbers, int from, int to) {
	std::vector<float>::iterator end = numbers.begin() + to;
	for (std::vector<float>::iterator i = numbers.begin() + from; i <= end; i++)
	{
		*i *= arg;
	}
}
void TagsManager::aggSum(std::vector<float>& numbers, int from, int to) {
	int count = from;
	float sum = 0;
	std::vector<float>::iterator iter = numbers.begin() + from;
	while (count <= to) {
		sum += *iter;
		iter = numbers.erase(iter);
		count++;
	}
	numbers.insert(iter, sum);
}
void TagsManager::aggPro(std::vector<float>& numbers, int from, int to) {
	int count = from;
	float pro = 1;
	std::vector<float>::iterator iter = numbers.begin() + from;
	while (count <= to) {
		pro *= *iter;
		iter = numbers.erase(iter);
		count++;
	}
	numbers.insert(iter, pro);
}
void TagsManager::aggAvg(std::vector<float>& numbers, int from, int to) {
	int count = from;
	float sum = 0;
	std::vector<float>::iterator iter = numbers.begin() + from;
	while (count <= to) {
		sum += *iter;
		iter = numbers.erase(iter);
		count++;
	}
	numbers.insert(iter, sum / (to - from + 1));
}
void TagsManager::aggFst(std::vector<float>& numbers, int from, int to) {
	if (from >= to)
		return;
	from += 1;
	int count = from;
	std::vector<float>::iterator iter = numbers.begin() + from;
	while (count <= to) {
		iter = numbers.erase(iter);
		count++;
	}
}
void TagsManager::aggLst(std::vector<float>& numbers, int from, int to) {
	if (from >= to)
		return;
	to -= 1;
	int count = from;
	std::vector<float>::iterator iter = numbers.begin() + from;
	while (count <= to) {
		iter = numbers.erase(iter);
		count++;
	}
}
void TagsManager::srtRev(std::vector<float>& numbers, int from, int to) {
	if (from >= to)
		return;
	int mid_num = (to + from) / 2;
	std::vector<float>::iterator end = numbers.begin() + to;
	std::vector<float>::iterator mid = numbers.begin() + mid_num;
	for (std::vector<float>::iterator i = numbers.begin() + from; i <= mid; i++)
	{
		float temp = *i;
		*i = *end;
		*end = temp;
		end--;
	}
}

void TagsManager::srtOrd(const std::string& order, std::vector<float>& numbers, int from, int to) {
	if (from >= to)
		return;
	std::vector<float>::iterator start = numbers.begin() + from;
	std::vector<float>::iterator end = numbers.begin() + to + 1;
	if (order == "ASC") {
		std::sort(start, end);
	}
	else {
		std::sort(start, end, std::greater<float>());
	}
}
void TagsManager::srtSlc(int arg, std::vector<float>& numbers, int from, int to) {
	if (from > to || arg <= 0)
		return;
	int count = from;
	std::vector<float>::iterator iter = numbers.begin() + from;
	while (count <= to && arg > 0) {
		iter = numbers.erase(iter);
		count++;
		arg--;
	}
}
void TagsManager::srtDst(std::vector<float>& numbers, int from, int to) {
	if (from >= to)
		return;
	std::queue<float> temp_storing;
	std::vector<float> sorted_area;
	int count = from;
	std::vector<float>::iterator iter = numbers.begin() + from;
	while (count <= to) {
		temp_storing.push(*iter);
		sorted_area.push_back(*iter);
		iter = numbers.erase(iter);
		count++;
	}
	std::sort(sorted_area.begin(), sorted_area.end());
	std::vector<float>::iterator iter_sort = sorted_area.begin() + 1;
	count = from + 1;
	while (count <= to) {
		if (*iter_sort == *(iter_sort - 1)) {
			iter_sort = sorted_area.erase(iter_sort);
		}
		else {
			iter_sort++;
		}
		count++;
	}
	//3,4,8
	while (!temp_storing.empty()) {
		float& current_number = temp_storing.front();

		std::vector<float>::iterator end = sorted_area.end();
		bool found = false;
		for (std::vector<float>::iterator i = sorted_area.begin(); i < end && current_number >= *i; i++)
		{
			if (*i == current_number) {
				found = true;
				sorted_area.erase(i);
				break;
			}

		}
		if (found) {
			iter = numbers.insert(iter, current_number) + 1;
		}
		temp_storing.pop();

	}

}
bool TagsManager::doesTagExist(Tag& input)
{
	int id = identifyTag(input);
	input.setId(id);
	return (id != -1);
}

bool TagsManager::doesTagExist(const Tag& input) const
{
	int id = identifyTag(input);
	return (id != -1);
}

void TagsManager::executeTag(const Tag& input, std::vector<float>& numbers)
{
	const std::string& tag_name = input.getName();
	if (tag_name == "MAP-INC") {
		mapInc(input.getAdditionalInfoFloat(), numbers, input.getFrom(), input.getTo());
	}
	else if (tag_name == "MAP-MLT") {
		mapMlt(input.getAdditionalInfoFloat(), numbers, input.getFrom(), input.getTo());
	}
	else if (tag_name == "AGG-SUM") {
		aggSum(numbers, input.getFrom(), input.getTo());
	}
	else if (tag_name == "AGG-PRO") {
		aggPro(numbers, input.getFrom(), input.getTo());
	}
	else if (tag_name == "AGG-AVG") {
		aggAvg(numbers, input.getFrom(), input.getTo());
	}
	else if (tag_name == "AGG-FST") {
		aggFst(numbers, input.getFrom(), input.getTo());
	}
	else if (tag_name == "AGG-LST") {
		aggLst(numbers, input.getFrom(), input.getTo());
	}
	else if (tag_name == "SRT-REV") {
		srtRev(numbers, input.getFrom(), input.getTo());
	}
	else if (tag_name == "SRT-ORD") {
		srtOrd(input.getAdditionalInfoString(), numbers, input.getFrom(), input.getTo());
	}
	else if (tag_name == "SRT-SLC") {
		srtSlc(input.getAdditionalInfoFloat(), numbers, input.getFrom(), input.getTo());
	}
	else if (tag_name == "SRT-DST") {
		srtDst(numbers, input.getFrom(), input.getTo());
	}
	else {
		throw MyException();
	}
	
}

bool TagsManager::isAdditionalInfoCorrect(const std::string& info, int id)
{
	char mask_additional_info_type = tag_masks[id].getAdditionalInfoType();
	if (mask_additional_info_type == '\0') {
		throw MyException(e_type::parser, "'" + tag_masks[id].getName() + "' does not expect additional info.");
	}
	else if (mask_additional_info_type == 'N') {
		throw MyException(e_type::parser, "'" + tag_masks[id].getName() + "' does not accept additional info type string.");
	}

	return tag_masks[id].isAdditionalInfoAccepted(info);
}

bool TagsManager::isAdditionalInfoCorrect(float info, int id)
{
	char mask_additional_info_type = tag_masks[id].getAdditionalInfoType();
	if (mask_additional_info_type == '\0') {
		throw MyException(e_type::parser, "'" + tag_masks[id].getName() + "' does not expect additional info.");
		return false;
	}
	else if (mask_additional_info_type == 'S') {
		throw MyException(e_type::parser, "'" + tag_masks[id].getName() + "' does not accept additional info type number.");
		return false;
	}
	return true;
}
