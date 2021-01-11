#pragma once
#include "Tag.h"
#include "TagMask.h"
#include <vector>
class TagsManager {
	//The tag management can be done alot better, but for the few hours left before the deadline this is all I can do.
	const std::vector<TagMask> tag_masks =
	{
		TagMask("MAP-INC",'N'),
		TagMask("MAP-MLT",'N'),
		TagMask("AGG-SUM"),
		TagMask("AGG-PRO"),
		TagMask("AGG-AVG"),
		TagMask("AGG-FST"),
		TagMask("AGG-LST"),
		TagMask("SRT-REV"),
		TagMask("SRT-ORD",'S',{"ASC","DSC"}),
		TagMask("SRT-SLC",'N'),
		TagMask("SRT-DST")
	
	};
	int identifyTag(const Tag& input)const;

	void mapInc(float arg, std::vector<float>& numbers, int from, int to);
	void mapMlt(float arg, std::vector<float>& numbers, int from, int to);
	void aggSum(std::vector<float>& numbers, int from, int to);
	void aggPro(std::vector<float>& numbers, int from, int to);
	void aggAvg(std::vector<float>& numbers, int from, int to);
	void aggFst(std::vector<float>& numbers, int from, int to);
	void aggLst(std::vector<float>& numbers, int from, int to);
	void srtRev(std::vector<float>& numbers, int from, int to);
	void srtOrd(const std::string& order,std::vector<float>& numbers, int from, int to);
	void srtSlc(int arg,std::vector<float>& numbers, int from, int to);
	void srtDst(std::vector<float>& numbers, int from, int to);


public:
	bool doesTagExist( Tag& input) ;
	bool doesTagExist(const Tag& input)const ;
	void executeTag(const Tag& input, std::vector<float>& numbers);
	bool isAdditionalInfoCorrect(const std::string& info,int id);
	bool isAdditionalInfoCorrect(float info,int id);
};