
// test case 4 and 6 will not work: replit has limited ram


#include <iostream>
using namespace std;

int map[200][200] = { 0 }, trails[1010][2] = { 0 };
int x = 100, y = 100;
int trail, moves, face = 0, place = 0;
int i, j, n, count1 = 0, cnt, flag = 0;
string instruct;


void print() {
    for (i = x - 10; i < x + 10; i++) {
        for (j = y - 10; j < y + 10; j++) {
            // if (i == 100 && j == 100){
            //   cout << "*  ";
            //   continue;
            // }
            if (map[i][j] == 0) cout << "-  ";
            else cout << map[i][j] << ' ';
            if (map[i][j] < 10 and map[i][j] != 0) cout << ' ';
        }
        cout << '\n';
    }
    cout << '(' << y - 100 << ", " << -x + 100 << ')' << '\n';
}

void forward() {
    place += 1;
    if (place == trail) {
        place = 0;
    }
    for (int i = 0; i < 4; i++) {
        if (face == 1) {
            if (map[x][y + 1] == 0) {
                y++;
                map[trails[place][0]][trails[place][1]] = 0;
                trails[place][0] = x;
                trails[place][1] = y;

                return;
            }
            else {
                if (map[x + 1][y] == 0) {
                    x++;
                    map[trails[place][0]][trails[place][1]] = 0;
                    trails[place][0] = x;
                    trails[place][1] = y;
                    face = 2;

                    return;
                }
                if (map[x][y - 1] == 0) {
                    y--;
                    map[trails[place][0]][trails[place][1]] = 0;
                    trails[place][0] = x;
                    trails[place][1] = y;
                    face = 3;

                    return;
                }
                if (map[x - 1][y] == 0) {
                    x--;
                    map[trails[place][0]][trails[place][1]] = 0;
                    trails[place][0] = x;
                    trails[place][1] = y;
                    face = 0;

                    return;
                }
                cout << '(' << y - 100 << ",1 " << -x + 100 << ')';
                print();
                exit(0);
            }
        }
        if (face == 0) {
            if (map[x - 1][y] == 0) {
                x--;
                map[trails[place][0]][trails[place][1]] = 0;
                trails[place][0] = x;
                trails[place][1] = y;

                return;
            }
            else {
                if (map[x][y + 1] == 0) {
                    y++;
                    map[trails[place][0]][trails[place][1]] = 0;
                    trails[place][0] = x;
                    trails[place][1] = y;
                    face = 1;

                    return;
                }
                if (map[x + 1][y] == 0) {
                    x++;
                    map[trails[place][0]][trails[place][1]] = 0;
                    trails[place][0] = x;
                    trails[place][1] = y;
                    face = 2;

                    return;
                }
                if (map[x][y - 1] == 0) {
                    y--;
                    map[trails[place][0]][trails[place][1]] = 0;
                    trails[place][0] = x;
                    trails[place][1] = y;
                    face = 3;

                    return;
                }
                cout << '(' << y - 100 << ",1 " << -x + 100 << ')';
                print();
                exit(0);
            }
        }
        if (face == 3) {
            if (map[x][y - 1] == 0) {
                y--;
                map[trails[place][0]][trails[place][1]] = 0;
                trails[place][0] = x;
                trails[place][1] = y;

                return;
            }
            else {
                if (map[x - 1][y] == 0) {
                    x--;
                    map[trails[place][0]][trails[place][1]] = 0;
                    trails[place][0] = x;
                    trails[place][1] = y;
                    face = 0;

                    return;
                }
                if (map[x][y + 1] == 0) {
                    y++;
                    map[trails[place][0]][trails[place][1]] = 0;
                    trails[place][0] = x;
                    trails[place][1] = y;
                    face = 1;

                    return;
                }
                if (map[x + 1][y] == 0) {
                    x++;
                    map[trails[place][0]][trails[place][1]] = 0;
                    trails[place][0] = x;
                    trails[place][1] = y;
                    face = 2;

                    return;
                }
                cout << '(' << y - 100 << ",1 " << -x + 100 << ')';
                print();
                exit(0);
            }
        }
        if (face == 2) {
            if (map[x + 1][y] == 0) {
                x++;
                map[trails[place][0]][trails[place][1]] = 0;
                trails[place][0] = x;
                trails[place][1] = y;

                return;
            }
            else {
                if (map[x][y - 1] == 0) {
                    y--;
                    map[trails[place][0]][trails[place][1]] = 0;
                    trails[place][0] = x;
                    trails[place][1] = y;
                    face = 3;

                    return;
                }
                if (map[x - 1][y] == 0) {
                    x--;
                    map[trails[place][0]][trails[place][1]] = 0;
                    trails[place][0] = x;
                    trails[place][1] = y;
                    face = 0;

                    return;
                }
                if (map[x][y + 1] == 0) {
                    y++;
                    map[trails[place][0]][trails[place][1]] = 0;
                    trails[place][0] = x;
                    trails[place][1] = y;
                    face = 1;

                    return;
                }
                cout << '(' << y - 100 << ",1 " << -x + 100 << ')';
                cout << moves;
                print();
                exit(0);
            }
        }
    }
    return;
}

int main() {
    string pause;
    int move;
    cin >> trail >> instruct >> moves;
    move = moves;
    // trail++;
    map[100][100] = 1;
    face = 0;
    n = instruct.length();
    trails[0][0] = 100;
    trails[0][1] = 100;
    while (moves > 0) {
        // cin >> pause;
        moves--;
        if (x == 1 or y == 1 or x == 199 or y == 199) {
            cout << "Array: out of range - x: " << x << " y: " << y << '\n';
            exit(0);
        }

        // for (i = 0; i < 200; i++){
        //   for (j = 0; j < 200; j++){
        //     if (map[i][j] == trail){
        //       map[i][j] = 0;
        //       continue;
        //     }
        //     if (map[i][j] != 0){
        //       map[i][j] += 1;
        //     }
        //   }
        // }

        if (instruct[count1 % n] == 'F') {
            // cout << 'F' << endl;
            forward();
        }
        else {
            if (instruct[count1 % n] == 'R') {
                // cout << 'R' << endl;
                face++;
                face %= 4;
                forward();
            }
            if (instruct[count1 % n] == 'L') {
                //   cout << 'L' << endl;
                face--;
                if (face == -1) face = 3;
                forward();
            }
        }

        // cout << x << ' ' << y << '\n';
        if (move - moves >= trail) {
            for (i = 0; i < trail; i++) {
                cout << trails[i][0] << ' ' << trails[i][1] << ' ' << map[trails[i][0]][trails[i][1]] << '\n';
                map[trails[i][0]][trails[i][1]] += 1;
            }
        }
        else {
            for (i = 0; i < move - moves; i++) {
                cout << trails[i][0] << ' ' << trails[i][1] << ' ' << map[trails[i][0]][trails[i][1]] << '\n';
                map[trails[i][0]][trails[i][1]] += 1;
            }
        }

        // cout << x-100 << ' ' << y-100 << endl;
        count1++;
        print();
    }
    print();
    cout << '(' << y - 100 << ", " << -x + 100 << ')';
}
