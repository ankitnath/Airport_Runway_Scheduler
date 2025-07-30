// scheduler GUI for runway

#pragma once
#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <vector>
#include <queue>
#include "runway.hpp"

class SchedulerGUI : public QMainWindow {
    Q_OBJECT

public:
    SchedulerGUI(int numRunways, QWidget* parent = nullptr);

private slots:
    void addDummyRequests();
    void processRequests();

private:
    void addRequest(const std::string& flightNumber, RequestType type, int priority);
    void addToTable(const Request& req, int runwayID);

    std::priority_queue<Request> queue;
    std::vector<Runway> runways;
    int requestCounter = 0;
    QTableWidget* table;
};
