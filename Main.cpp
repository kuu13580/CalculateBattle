#include "common.h"
#include "Title.h"
#include "Game.h"

// クリア
class Clear : public App::Scene
{
public:

	Clear(const InitData& init) : IScene{ init } {}

	void update() override
	{
		//タイトルに戻る
		if (SimpleGUI::Button(get_text(U"TXT_RETURN_BTN", getData().lang, getData().texts), Vec2{ 300, 400 }, 200)) changeScene(U"Title");
		// 言語変更ボタン
		if (SimpleGUI::Button(get_text(U"TXT_LANGUAGE", Language((getData().lang + 1) % (Language::Language_MAX + 1)), getData().texts), Vec2{ 350, 500 }, 100)) getData().lang = Language((getData().lang + 1) % (Language::Language_MAX + 1));

	}

	void draw() const override
	{
		Scene::SetBackground(Palette::Lightgoldenrodyellow);
		FontAsset(U"TitleFont")(U"CLEAR").drawAt(400, 200, Palette::Black);
	}
};

// GAMEOVER
class GameOver : public App::Scene
{
public:

	GameOver(const InitData& init) : IScene{ init } {}

	void update() override
	{
		//タイトルに戻る
		if (SimpleGUI::Button(get_text(U"TXT_RETURN_BTN", getData().lang, getData().texts), Vec2{ 300, 450 }, 200)) changeScene(U"Title");
		if (SimpleGUI::Button(get_text(U"TXT_LANGUAGE", Language((getData().lang + 1) % (Language::Language_MAX + 1)), getData().texts), Vec2{ 350, 500 }, 100)) getData().lang = Language((getData().lang + 1) % (Language::Language_MAX + 1));
	}

	void draw() const override
	{
		Scene::SetBackground(Palette::Orangered);
		FontAsset(U"Question")(U"GAME OVER").drawAt(Scene::Center(), Palette::Black);
	}
};

void Main()
{

	FontAsset::Register(U"TitleFont", 60, Typeface::Heavy);
	FontAsset::Register(U"ScoreFont", 30, Typeface::Bold);
	FontAsset::Register(U"Question", 100, Typeface::Bold);
	FontAsset::Register(U"Explain", 20, Typeface::Regular);

	// シーンマネージャーを作成
	// ここで GameData が初期化される
	App manager;
	manager.add<Title>(U"Title");
	manager.add<Game>(U"Game");
	manager.add<Clear>(U"Clear");
	manager.add<GameOver>(U"GameOver");

	while (System::Update())
	{
		if (not manager.update())
		{
			break;
		}
	}
}


