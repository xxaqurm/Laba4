#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include "algorithms.h"

using namespace std;

string bordaMethod(map<string, int> candidates, map<string, vector<string>> voters) {
    /* Реализация метода Борда */
    for (auto& voter : voters) {
        vector<string> votes = voter.second;
        for (int i = 0; i < votes.size(); i++) {
            candidates[votes[i]] += votes.size() - i - 1;
        }
    }

    int maxScore = 0;
    string winner;
    for (auto& candidate : candidates) {
        if (candidate.second > maxScore) {
            maxScore = candidate.second;
            winner = candidate.first;
        }
    }

    return winner;
}

string condorcetMethod(map<string, int> candidates, map<string, vector<string>> voters) {
    /* Реализация метода Кондорсе*/
    for (auto& cnadidate : candidates) {
        for (auto& candidate2 : candidates) {
            if (cnadidate.first != candidate2.first) {
                int score1 = 0;
                int score2 = 0;
                for (auto& voter : voters) {
                    vector<string> votes = voter.second;
                    if (find(votes.begin(), votes.end(), cnadidate.first) < find(votes.begin(), votes.end(), candidate2.first)) {
                        score1++;
                    } else {
                        score2++;
                    }
                }
                if (score1 > score2) {
                    cnadidate.second++;
                } else {
                    candidate2.second++;
                }
            }
        }
    }

    string winner;
    int maxScore = 0;
    for (auto& candidate : candidates) {
        if (candidate.second > maxScore) {
            maxScore = candidate.second;
            winner = candidate.first;
        }
    }
    
    return winner;
}