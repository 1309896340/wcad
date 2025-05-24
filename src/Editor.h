#pragma once

#include <QMainWindow>
#include <QKeyEvent>
#include <QSplitter>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QToolButton>

#include <memory>
#include <cstdint>
#include <string>

#include "Canvas.h"

class Toolbar : public QWidget {
public:
	Toolbar(QWidget* parent = nullptr);
};

class Editor : public QMainWindow {
	Q_OBJECT
public:
	enum ToolMode {
		CURSOR, PEN
	};
private:
	ToolMode mode;
	std::array<QCursor, 2> cursors;
	QSplitter* splitter{ nullptr };
	Canvas* canvas{ nullptr };
	Toolbar* toolbar{ nullptr };
	QVBoxLayout* tool_layout{nullptr};
	QButtonGroup* tool_group{ nullptr };
	QToolButton* tool_cursor{ nullptr }, * tool_pen{ nullptr };
	std::vector<QToolButton*> tool_buttons;
private slots:
	void onToolCursorClick();
	void onToolPenClick();
public:
	Editor(std::string title);

	void changeMode(ToolMode mode);
	void keyPressEvent(QKeyEvent* event) override;
};
