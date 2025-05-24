#include "Editor.h"

constexpr int TOOLBAR_WIDTH = 40;

Toolbar::Toolbar(QWidget* parent) :QWidget(parent) {}


void Editor::onToolCursorClick(){
	if (!this->tool_cursor->isChecked())
		return;
	this->changeMode(CURSOR);
}
void Editor::onToolPenClick() {
	if (!this->tool_pen->isChecked())
		return;
	this->changeMode(PEN);
}

Editor::Editor(std::string title) {
	this->setWindowTitle(QString::fromStdString(title));
	// 默认大小配置
	this->setMinimumWidth(1000);
	this->setMinimumHeight(800);
	// 加载光标
	this->cursors[0] = QCursor();
	this->cursors[1] = QCursor(QPixmap("Debug/assets/icons/pen.png"), 2, 17);
	// 窗口布局
	this->splitter = new QSplitter(this);
	this->toolbar = new Toolbar(this->splitter);
	this->canvas = new Canvas(this->splitter);
	this->tool_layout = new QVBoxLayout(this->toolbar);
	this->tool_group = new QButtonGroup(this->toolbar);
	this->tool_cursor = new QToolButton(this->toolbar);
	this->tool_pen = new QToolButton(this->toolbar);

	this->setAttribute(Qt::WA_StyledBackground, true);
	this->setWindowIcon(QIcon(QString("Debug/assets/icons/favicon.png")));
	this->setCentralWidget(this->splitter);
	this->splitter->addWidget(this->toolbar);
	this->splitter->addWidget(this->canvas);

	this->tool_cursor->setCheckable(true);
	this->tool_cursor->setIcon(QIcon(QString("Debug/assets/icons/cursor.png")));
	this->tool_pen->setCheckable(true);
	this->tool_pen->setIcon(QIcon(QString("Debug/assets/icons/pen.png")));

	connect(this->tool_cursor, &QToolButton::clicked, this, &Editor::onToolCursorClick);
	connect(this->tool_pen, &QToolButton::clicked, this, &Editor::onToolPenClick);

	this->tool_cursor->setChecked(true);

	this->tool_group->addButton(this->tool_cursor);
	this->tool_group->addButton(this->tool_pen);

	this->toolbar->setFixedWidth(TOOLBAR_WIDTH);
	this->toolbar->setLayout(this->tool_layout);

	this->tool_layout->setSpacing(5);
	this->tool_layout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
	this->tool_layout->addWidget(this->tool_cursor);
	this->tool_layout->addWidget(this->tool_pen);

	this->splitter->show();
	this->show();
}

void Editor::changeMode(ToolMode mode) {
	switch (mode) {
	case CURSOR:
		setCursor(this->cursors[0]);
		break;
	case PEN:
		setCursor(this->cursors[1]);
		break;
	default:
		break;
	}
}

void Editor::keyPressEvent(QKeyEvent* event) {
	switch (event->key()) {
	case Qt::Key_A:
		changeMode(PEN);
		break;
	case Qt::Key_B:
		changeMode(CURSOR);
		break;
	}
}
