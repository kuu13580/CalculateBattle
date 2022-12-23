# include "stdafx.h"
String get_text(String id, Data::Language lang, HashTable<String, Text>& texts) {
	switch (lang) {
	case Data::Language_Japanese:
		return texts[id].japanese_text;
		break;
	case Data::Language_English:
		return texts[id].english_text;
		break;
	case Data::Language_Chinese:
		return texts[id].chinese_text;
		break;
	}
	String error = U"ERROR";
	return error;
}
