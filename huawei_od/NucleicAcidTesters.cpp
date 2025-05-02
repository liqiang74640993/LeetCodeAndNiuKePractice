#include <gtest/gtest.h>
#include <vector>
#include <queue>

//核酸检测人员安排
//题目描述
//在系统、网络均正常的情况下组织核酸采样员和志愿者对人群进行核酸检测筛查。每名采
//样员的效率不同，采样效率为 N 人/小时。由于外界变化，采样员的效率会以 M 人/小时为
//粒度发生变化，M 为采样效率浮动粒度，M=N10%，输入保证 N10%的结果为整数。采样员
//效率浮动规则：采样员需要一名志愿者协助组织才能发挥正常效率，在此基础上，每增加
//一名志愿者，效率提升 1M，最多提升 3M；如果没有志愿者协助组织，效率下降 2M。
//怎么安排速度最快？求总最快检测效率（总检查效率为各采样人员效率值相加）。
//输入描述
//第一行：第一个值，采样员人数，取值范围[1,100]；第二个值，志愿者人数，取值范围[1,
//500]；
//第二行：各采样员基准效率值(单位人/小时)，取值范围[60,600]，保证序列中每项值计算 1
//0%为整数
//输出描述
//第一行：总最快检测效率(单位人/小时)

using namespace std;

TEST(HuaWeiOd, NucleicAcidTessters)
{
    //方法1:网上找的,没看懂
    //最多100个采样员
    const int N= 110;
    int q[N];
    int n1,n2;
        cin>>n1>>n2;
        int res=0;
        for(int i=0;i<n1;i++){
            cin>>q[i];
            res+=q[i]*0.8; //不配置志愿者的效率
        }
        //sort(q,q+n1,cmp);
        priority_queue<int,vector<int>,less<int>> myq;
        for(int i=0;i<n1;i++){
            myq.push(0.2*q[i]);
            myq.push(0.1*q[i]);
            myq.push(0.1*q[i]);
            myq.push(0.1*q[i]);
        }
        while(n2--){
            res+=myq.top();
            myq.pop();
        }
        cout<<res<<endl;



     //方法2
    int sampler = 0, volunteer = 0;
    //input 第一个值，采样员人数，取值范围[1,100]；第二个值，志愿者人数，取值范围[1,500]；
    std::cin >> sampler >> volunteer;
    //input 采样员基准效率值(单位人/小时)，取值范围[60,600]
    vector<int> efficiencyVec;
    int samlerEfficiency = 0;
    for(int i = 0; i < sampler; ++i){
        std::cin >> samlerEfficiency;
        efficiencyVec.emplace_back(samlerEfficiency);
    }
    //sort 采样员基准效率值(单位人/小时)
    sort(efficiencyVec.begin(),efficiencyVec.end(),std::greater<int>());
    //如果大于4个志愿者,则将4个志愿者分配给最快的核酸检测人员 ,如果小于等于4个志愿者决定是否留一个人员给排序后的第二个核酸检测人员
    int tempVolunteer;
    int allEfficiency = 0;
    for(auto iterEfficiency = efficiencyVec.begin(); iterEfficiency != efficiencyVec.end(); ++iterEfficiency){
        tempVolunteer = volunteer;
        if(tempVolunteer > 4){ //大于4个志愿者
            volunteer -= 4;
            allEfficiency += (*iterEfficiency) *  1.3;//4 volunteer提升3M
        }else{ //小于等于4个自愿者
            if(tempVolunteer == 0){
                allEfficiency += (*iterEfficiency) * 0.8;//没有志愿者协助组织，效率下降 2M。
            }else if(tempVolunteer == 1){
                allEfficiency += (*iterEfficiency); // 一名志愿者协助组织才能发挥正常效率
                volunteer = 0; //无志愿者使用
            }else { //计算剩余自愿者为2,3,4该如何分配
                if(++iterEfficiency == efficiencyVec.end()){ //最后一个核酸检测人员,全部分配
                     --iterEfficiency;
                    allEfficiency += (*iterEfficiency) *(1 + 0.1 * (tempVolunteer - 1));//
                }else{//至少还存在2个核酸检测人员,看怎么分配合理(全部分配给排序后的第一个检测人员,或者分配给排序后的前2个检测人员,第二个检测人员分配1个)
                    auto nextIterEfficiency = iterEfficiency;
                    --iterEfficiency;
                    int tempEfficiency1 = (*iterEfficiency) *(1 + 0.1 * (tempVolunteer - 1)) + (*nextIterEfficiency) *0.8;//全部分配给最高效率的检测人员
                    int tempEfficiency2 = (*iterEfficiency) *(1 + 0.1 * (tempVolunteer - 2)) + (*nextIterEfficiency);
                    if(tempEfficiency1 >= tempEfficiency2){
                        allEfficiency += (*iterEfficiency) *(1 + 0.1 * (tempVolunteer - 1));
                        volunteer = 0;
                    }else{
                        allEfficiency += (*iterEfficiency) *(1 + 0.1 * (tempVolunteer - 2));
                        volunteer = 1;
                    }
                }
            }
        }
    }
    std::cout << allEfficiency << std::endl;
}
