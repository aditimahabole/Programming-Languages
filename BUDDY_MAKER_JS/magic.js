const magic_input = document.querySelector("#magic_input") ;
const magic_button = document.querySelector("#magic_button");
const magic_ans = document.querySelector("#ans");
let a =0;
magic_button.onmouseover = function()
{
    function buttonMoveLeft()
    {
        console.log(magic_input);
        magic_button.style.transform = 'translateX(-200%)'
        if(magic_input.value ==="")
        {
            magic_ans.textContent = "Please Buddy";
        }
        else if (magic_input.value === "no"||magic_input.value === "No"|| magic_input.value === "NO" || magic_input.value === "nO" ||magic_input.value === "")
        {
            magic_ans.textContent = "Don't say No...Please";
        }
        
    }
    function buttonMoveRight()
    {
        console.log(magic_input.value);
        magic_button.style.transform = 'translateX(200%)'
        magic_ans.textContent = "Please write Yes Buddy";
        if(magic_input.value ==="")
        {
            magic_ans.textContent = "Please write Yes";
        }
        else if (magic_input.value === "no"||magic_input.value === "No"|| magic_input.value === "NO" || magic_input.value === "nO" ||magic_input.value === "")
        {
            magic_ans.textContent = "I can't accept your 'No'!";
        }
    }
    function Reset()
    {
        magic_ans.textContent = "";
        magic_input.value = ""
        magic_button.style.backgroundColor= "darkblue";
        magic_button.style.boxShadow= " 0 0 20px 0 darkblue";
    }
    if((magic_input.value === "no"||magic_input.value === "No"|| magic_input.value === "NO" || magic_input.value === "nO" ||magic_input.value === "" ) && a == 0)
    {
        buttonMoveLeft();
        magic_button.style.backgroundColor= "darkblue";
        magic_button.style.boxShadow= " 0 0 20px 0 darkblue";
        a=1;
        return false;
    }
    if((magic_input.value === "no"||magic_input.value === "No"|| magic_input.value === "NO" || magic_input.value === "nO" ||magic_input.value === "" ) && a == 1)
    {
        buttonMoveRight();
        magic_button.style.backgroundColor= "darkblue";
        magic_button.style.boxShadow= " 0 0 20px 0 darkblue";
        a=2;
        return false;
    }
    if((magic_input.value === "no"||magic_input.value === "No"|| magic_input.value === "NO" || magic_input.value === "nO" ||magic_input.value === "" )&& a == 2)
    {
        buttonMoveLeft();
        magic_button.style.backgroundColor= "darkblue";
        magic_button.style.boxShadow= " 0 0 20px 0 darkblue";
        a=1;
        return false;
    }
    if(magic_input.value!=="yes"|| magic_input.value!=="Yes" || magic_input.value!=="YES" )
    {
        console.log(magic_input.value);
        magic_button.style.cursor = "pointer"
        magic_button.style.backgroundColor= "lightgreen";
        magic_button.style.boxShadow= " 0 0 20px 0 lightgreen";
        magic_ans.textContent = "Yay you are my friend!";
        setTimeout(Reset,5000)




    }

}