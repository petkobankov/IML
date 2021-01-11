#pragma once
#include "Tag.h"
#include "TagMask.h"
#include <vector>
/// <summary>
/// Tags manager is the markup language itself. 
/// The implementation is not very scalable. I had another idea of making an abstract class and later creating children classes of it but for the little time I have left, this is what I could think of. 
/// </summary>
class TagsManager {
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
	//When first checking if a tag exists, if it does it's given an id. In our case the id is from 0 to 10; 
	//The id is used later for easier data access.
	int identifyTag(const Tag& input)const;

	//The function for each tag. 
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