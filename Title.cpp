#include "common.h"
#include "Title.h"
// タイトルシーン
Title::Title(const InitData& init)
	: IScene{ init }
{
	// データを設定
	BinaryReader reader{ U"data.bin" };
	if (not reader) // もしオープンに失敗したら
	{
		throw Error{ U"Failed to open `bin`" };
	}
	vector<uint8_t> data(reader.size());
	reader.read(data.data(), reader.size());
	auto object_data = GetData_list(data.data());

	// モンスターリスト初期化
	for (const auto& itr : *object_data->monsters()) {
		Monster buf;
		buf.name = Unicode::FromUTF8(itr->name()->c_str());
		buf.hp = itr->hp();
		buf.ap = itr->ap();
		buf.dp = itr->dp();
		buf.speed = itr->speed();
		buf.name_id = Unicode::FromUTF8(itr->name_id()->c_str());
		buf.emoji = Unicode::FromUTF8(itr->emoji()->c_str());
		getData().monsters << buf;
	}

	// テキストリスト初期化
	for (const auto& itr : *object_data->texts()) {
		Text buf;
		buf.japanese_text = Unicode::FromUTF8(itr->japanese()->c_str());
		buf.english_text = Unicode::FromUTF8(itr->english()->c_str());
		buf.chinese_text = Unicode::FromUTF8(itr->chinese()->c_str());
		getData().texts.emplace(Unicode::FromUTF8(itr->id()->c_str()), buf);
	}

	// プレイヤー初期化
	getData().player.hp = object_data->player()->hp();
	getData().player.ap = object_data->player()->ap();
	getData().player.dp = object_data->player()->dp();
}

void Title::update()
{
	// 開始ボタン
	if (SimpleGUI::Button(get_text(U"TXT_START_BTN", getData().lang, getData().texts), Vec2{ 350, 400 }, 100))
	{
		// ゲームシーンに遷移
		changeScene(U"Game");
	}
	// 言語変更ボタン
	if (SimpleGUI::Button(get_text(U"TXT_LANGUAGE", Language((getData().lang + 1) % (Language::Language_MAX + 1)), getData().texts), Vec2{ 350, 500 }, 100))
	{
		// 言語変更
		getData().lang = Language((getData().lang + 1) % (Language::Language_MAX + 1));
	}

}

void Title::draw() const
{
	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });
	FontAsset(U"TitleFont")(get_text(U"TXT_TITLE", getData().lang, getData().texts)).drawAt(400, 200, Palette::Black);

}
