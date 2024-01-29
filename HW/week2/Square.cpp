#include <cstdio>
#include <algorithm>

int N, M;
int length[25];

bool dfs(int, int, int, int, bool []);

int main()
{
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &M);
        int sum = 0, Max = 0;
        for (int i = 0; i < M; ++i) {
            scanf("%d", &length[i]);
            Max = std::max(Max, length[i]);
            sum += length[i];
        }
        if (sum%4 != 0 || Max > sum/4) {puts("no"); continue;}

        std::sort(length, length+M, [](const int &a, const int &b){return a>b;});

        bool used[25] = {0};
        if (dfs(0, 0, 0, sum / 4, used)) puts("yes");
        else puts("no");
    }
}
// num_of_edge: �ثe�w�g�զn�F�X����
// sum: �{�b�b�ƪ��o����w�g�ƤF�h��
// start: �q��start��stick�}�l�D��
// edge_length: �C�䪺���ץ����n�Ʀ�edge_length
// used[]: used[i]==true ��ܲ�i��stick�w�g�Q�D��
bool dfs(int num_of_edge, int sum, int start, const int edge_length, bool used[])
{
    if (num_of_edge == 3) return true;

    if (sum == edge_length)
        if (dfs(num_of_edge + 1, 0, 0, edge_length, used)) return true;

    for (int i = start; i < M; ++i) {
        if (!used[i] && sum + length[i] <= edge_length) {
            used[i] = true;
            if (dfs(num_of_edge, sum + length[i], i+1, edge_length, used))
                return true;
            used[i] = false;
        }
    }
    return false;
}
/*
ref:
https://gist.github.com/KT-Yeh/cb7004bb14e09d1fecc5
*/