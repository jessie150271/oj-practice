#include<iostream>
#include<string>
#include<vector>
#define NUMBER_OF_SAME_TYPE_CHARS 3;
using namespace std;

class FlyweightCharacter; /*Actual flyweight objects class(declaration)*/
						  /*讓『FlyweightCharacterAbstractBuilder』可以用這個class*/

//FlyweightCharacterAbstractBuilder is a class holding the properties which are shared by many objects.
//     So instead of keeping these properties in those objects we keep them externally, making objects flyweight.

class FlyweightCharacterAbstractBuilder
{
	FlyweightCharacterAbstractBuilder() {}//建構式
	~FlyweightCharacterAbstractBuilder() {}//結構式
public:
	/*static 佔據的記憶體直到.exe檔結束時才會消失，通常用來記錄狀態*/
	static vector<float> fontSizes;//lets imagine that sizes may be of floating point type
	static vector<string> fontNames;//font name may be of variable length
	static void setFontsAndNames();
	static FlyweightCharacter createFlyweightCharacter(unsigned short fontSizeIndex, 
		unsigned short fontNameIndex,
		unsigned short positionInStream);
	/*若有多個class FCAB型態的變數，static可保證所有class FCAB變數只會有1份data，
									且可確認data絕對不會被改變、節省記憶體、增加執行效率*/
};
vector<float> FlyweightCharacterAbstractBuilder::fontSizes(3);//初始化fontSizes
vector<string> FlyweightCharacterAbstractBuilder::fontNames(3);//初始化fontNames

void FlyweightCharacterAbstractBuilder::setFontsAndNames()
{
	fontSizes[0] = 1.0;
	fontSizes[1] = 1.5;
	fontSizes[2] = 2.0;
	fontNames[0] = "first_font";
	fontNames[1] = "second_font";
	fontNames[2] = "third_font";
}

class FlyweightCharacter
{
	unsigned short fontSizeIndex;//index instead of actual font size
	unsigned short fontNameIndex;//index instead of font name
	unsigned positionInStream;
public:
	FlyweightCharacter(unsigned short fontSizeIndex,
		unsigned short fontNameIndex,
		unsigned short positionInStream) 
		:fontSizeIndex(fontSizeIndex), fontNameIndex(fontNameIndex), positionInStream(positionInStream) {}
	void print()/*可在class內實做*/ /*把member function的<定義><宣告>在class裡面，稱為【in-line function】(很有效率)
																			相對為【macro function】*/
	{
		cout << "Font Size:" << FlyweightCharacterAbstractBuilder::fontSizes[fontSizeIndex]
			<< ",\tfont Name:" << FlyweightCharacterAbstractBuilder::fontNames[fontNameIndex]
			<< ",\tcharacter stream position:" << positionInStream << endl;
	}
	~FlyweightCharacter() {}
};

FlyweightCharacter FlyweightCharacterAbstractBuilder::createFlyweightCharacter(/*在 B class裡面生成 A class物件*/
	unsigned short fontSizeIndex, unsigned short fontNameIndex,
	unsigned short positionInStream)
{
	FlyweightCharacter fc(fontSizeIndex, fontNameIndex, positionInStream);/*會呼叫FC的contructor*/
	return fc;
}

int main(int argc, char** argv)
{
	vector<FlyweightCharacter> chars;
	FlyweightCharacterAbstractBuilder::setFontsAndNames();/*因為setFontsAndNames是static function，可當作global function用*/
	unsigned short limit = NUMBER_OF_SAME_TYPE_CHARS;
	for (unsigned short i = 0; i < limit; i++)
	{
		chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(0, 0, i));
		chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(1, 1, i + 1 * limit));
		chars.push_back(FlyweightCharacterAbstractBuilder::createFlyweightCharacter(2, 2, i + 2 * limit));
		/*僅存Index，實體資料存在FCAB的static變數*/
	}
	for (unsigned short i = 0; i < chars.size(); i++)
	{
		chars[i].print();
	}

    return 0;
}