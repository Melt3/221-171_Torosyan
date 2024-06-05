#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>

// Функция для выполнения поиска в ширину (BFS)
std::vector<std::string> bfs(const std::unordered_map<std::string, std::vector<std::string>>& graph, const std::string& start, const std::string& end) {
    std::queue<std::string> q;
    std::unordered_map<std::string, bool> visited;
    std::unordered_map<std::string, std::string> parent;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        std::string current = q.front();
        q.pop();

        if (current == end) {
            // Восстановление пути
            std::vector<std::string> path;
            for (std::string at = end; at != ""; at = parent[at]) {
                path.push_back(at);
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (const std::string& neighbor : graph.at(current)) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;
            }
        }
    }

    return {}; // Если путь не найден
}

int main() {
    // Определение графа лабиринта
    std::unordered_map<std::string, std::vector<std::string>> graph = {
        {"S", {"A", "E", "D", "B"}},
        {"A", {"S", "F"}},
        {"B", {"S", "D", "C"}},
        {"C", {"B", "J"}},
        {"D", {"S", "B", "E"}},
        {"E", {"S", "D", "G"}},
        {"F", {"A", "H"}},
        {"G", {"E", "I"}},
        {"H", {"F"}},
        {"I", {"G", "J"}},
        {"J", {"C", "I"}}
    };

    // Начальная и конечная точки
    std::string start = "S";
    std::string end = "I";

    // Поиск кратчайшего пути
    std::vector<std::string> path = bfs(graph, start, end);

    // Вывод пути
    if (!path.empty()) {
        std::cout << "Кратчайший путь от " << start << " до " << end << ": ";
        for (const std::string& room : path) {
            std::cout << room;
            if (room != end) {
                std::cout << " -> ";
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "Путь не найден." << std::endl;
    }

    return 0;
}
