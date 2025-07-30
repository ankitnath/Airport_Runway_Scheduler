// scheduler_gui.cpp
#include "scheduler_gui.hpp"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <ctime>

SchedulerGUI::SchedulerGUI(int numRunways, QWidget* parent)
    : QMainWindow(parent) {
    for (int i = 0; i < numRunways; ++i)
        runways.emplace_back(i + 1);

    QWidget* central = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(central);

    QPushButton* addRequestBtn = new QPushButton("Add Dummy Requests");
    connect(addRequestBtn, &QPushButton::clicked, this, &SchedulerGUI::addDummyRequests);

    QPushButton* processBtn = new QPushButton("Process Queue");
    connect(processBtn, &QPushButton::clicked, this, &SchedulerGUI::processRequests);

    table = new QTableWidget(0, 4);
    QStringList headers = {"Flight", "Type", "Priority", "Runway"};
    table->setHorizontalHeaderLabels(headers);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    layout->addWidget(addRequestBtn);
    layout->addWidget(processBtn);
    layout->addWidget(table);

    setCentralWidget(central);
    setWindowTitle("Airport Runway Scheduler");
    resize(600, 400);
}

void SchedulerGUI::addDummyRequests() {
    addRequest("LH123", RequestType::LANDING, 1);
    addRequest("EK202", RequestType::TAKEOFF, 2);
    addRequest("AA777", RequestType::LANDING, 0);
}

void SchedulerGUI::addRequest(const std::string& flightNumber, RequestType type, int priority) {
    Request req;
    req.id = ++requestCounter;
    req.flightNumber = flightNumber;
    req.type = type;
    req.priority = priority;
    req.requestTime = std::time(nullptr);
    queue.push(req);
}

void SchedulerGUI::processRequests() {
    while (!queue.empty()) {
        for (auto& runway : runways) {
            if (runway.isAvailable() && !queue.empty()) {
                Request req = queue.top();
                queue.pop();
                runway.occupy();
                addToTable(req, runway.getID());
                runway.release();
            }
        }
    }
}

void SchedulerGUI::addToTable(const Request& req, int runwayID) {
    int row = table->rowCount();
    table->insertRow(row);
    table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(req.flightNumber)));
    table->setItem(row, 1, new QTableWidgetItem(req.type == RequestType::LANDING ? "Landing" : "Takeoff"));
    table->setItem(row, 2, new QTableWidgetItem(QString::number(req.priority)));
    table->setItem(row, 3, new QTableWidgetItem(QString::number(runwayID)));
}
