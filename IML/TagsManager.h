#pragma once
#include "Tag.h"
#include "TagMask.h"
#include <vector>
class TagsManager {
	const std::vector<TagMask> tag_masks =
	{
		TagMask("MAP-INC",'N'),
		TagMask("MAP-MLT",'N'),
		TagMask("AGG-SUM"),
		TagMask("AGG-PRO"),
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
public:
	bool doesTagExist( Tag& input) ;
	bool doesTagExist(const Tag& input)const ;
	void executeTag(const Tag& input, std::vector<float>& numbers);
	bool isAdditionalInfoCorrect(const std::string& info,int id);
	bool isAdditionalInfoCorrect(float info,int id);
};