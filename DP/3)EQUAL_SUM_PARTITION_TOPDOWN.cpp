class Solution {
public:
  /*
  ISME PEHLE HUMNE DEKHA KI AGAR SUM EVEN HAI TABHI ARR TWO HALF ME BAATA JAA SAKTA HAI
  AGAR SUM ODD AYA TO LIKE 23 KA 11 12 ESE HI TO BATOGE HAINA
  CHALO AB HUMNE DUDNA HAI DO SUBSET JINKA SUM EQUAL HO
  BUT AGAR DEKHA JAAYE TO AGAR HUMNE EK SUBSET DUND LIYA JISKA SUM TOTAL SUM/2 KE BARABAR HO TO BAKI BACHA HUA SET KA SUM APNE AAP SAME AAJEGA
  LIKE AGAR TOTAL SUM 22 HAI TO SUNSET 1 KA SUM11 HONA CHHIAYE AND SUBSET 2 KA SUM BHI 11 HONA CHHAIYE 
  TO AGAR HUMNE EK SUBSET FIND KAR DIYA TO DUSRA BHI SAMEICH HOGA NA TO 
  ISS q KO HUM SUBSET SUM PRESENT SE HI KARENGE BAS YE TOTAL SUM WALI PROPERTY KA DYAAN RAKHNE KA HAI
  */
    bool canPartition(vector<int>& nums) 
    {
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            total+=nums[i];
        }
        if(total%2)
        {
            return false;
          //TOTAL AGAR 19 HUA TO ODD HAI TO ISKA TO PARTITION KISI JANAM ME NHI KAR SAKTE SO RETURN FALSE
        }
        else
        {
          // ELSE AGAR SUM EVEN HAI TO HAA BHAI ISS TWO EQUAL PART ME DEVIDE KAR SAKTE HAI
          //TO HUM HALF OF SUM FIND KARENGE TO AGAR VO PRESENT HUA TO BAKI KA ADHA TO  PRESENT HOGA HI NA BHAI
          //SUPPOSE TOTAL SUM 22 HAI TO 22 KA AADHA 11 AB AGAR ARRAY {5,5,1,11} HAI TO GAR HUM EK SUBSET D=FIND KAREDE
           // LIKE 5 5 1 PRESENT HAI TO BACHA KYA {11} AUR ISS SUBSET KA SUM BHI 11 HI AAGYA HAINA 
 
          
            int sum=total/2;
          
            int t[n+1][sum+1];
            for(int i=0;i<=n;i++)
            {
                t[i][0]=true;
            }
            for(int i=1;i<=sum;i++)
            {
                t[0][i]=false;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=sum;j++)
                {
                    if(nums[i-1]<=j)
                    {
                        t[i][j]=t[i-1][j-nums[i-1]] || t[i-1][j];
                    }
                    else
                    {
                        t[i][j]=t[i-1][j];
                    }
                }
            }
            return t[n][sum];
            
        }
    }
};
