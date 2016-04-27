#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int get_pos(string name){
    if(name == "Alice") return 1;
    if(name == "Ariel") return 1;
    if(name == "Aurora") return 1;
    if(name == "Phil") return 1;
    if(name == "Peter") return 1;
    if(name == "Olaf") return 1;
    if(name == "Phoebus") return 1;
    if(name == "Ralph") return 1;
    if(name == "Robin") return 1;

    if(name == "Bambi") return 2;
    if(name == "Belle") return 2;
    if(name == "Bolt") return 2;
    if(name == "Mulan") return 2;
    if(name == "Mowgli") return 2;
    if(name == "Mickey") return 2;
    if(name == "Silver") return 2;
    if(name == "Simba") return 2;
    if(name == "Stitch") return 2;

    if(name == "Dumbo") return 3;
    if(name == "Genie") return 3;
    if(name == "Jiminy") return 3;
    if(name == "Kuzko") return 3;
    if(name == "Kida") return 3;
    if(name == "Kenai") return 3;
    if(name == "Tarzan") return 3;
    if(name == "Tiana") return 3;
    if(name == "Winnie") return 3;
}

int main(){
    int n;
    int cur_pos = 1, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i ++){
        string tmp;
        cin >> tmp;
        int pos = get_pos(tmp);
        ans += abs(pos - cur_pos);
        cur_pos = pos;
    }
    cout << ans << endl;
}
