// BOX COMPONENT
import React from "react"
export default function Box(props) {
    const styles = {
        backgroundColor: props.on ? "#222222" : "transparent" // yaha props.on ki value  chnage hogi to color bhi chnage ho jaenga
    }
    return (
        <div 
            style={styles} 
            className="box"
            onClick={()=>props.toggle(props.id)} // yaha onClick karke par props.toggle call hoga and usme props.id value pass hogi 
        >
        </div>
    )
}
// --------------------------------------------------------------------------------------------
// APP COMPONENT
import React from "react"
import boxes from "./boxes"
import Box from "./Box"
export default function App() {
    const [squares, setSquares] = React.useState(boxes)
    
    function toggle(id) {
//       Box compoenent se ye id pass ho rhi hai
      // value set kar rhe neeche
      //prevSauqres matlab jitne bhi Squares hai
        setSquares(prevSquares => {
            const newSquares = [] // ek new araay banaya
            for(let i = 0; i < prevSquares.length; i++) { //loop kiya prevSquares pe sare
                const currentSquare = prevSquares[i] 
                if(currentSquare.id === id) { //agar id same hai to updateSquare object me swtich karo value of on
                    const updatedSquare = {
                        ...currentSquare,
                        on: !currentSquare.on
                    }
                    newSquares.push(updatedSquare) //yaha newSuare me push karo updated value
                } else {
                    newSquares.push(currentSquare) // agar id match nhi karti to simple puch karo uss pure element ko
                }
            }
            return newSquares //return kardo newSquares array
        })
    }
    const squareElements = squares.map(square => (
        <Box 
            key={square.id} 
            id={square.id}
            on={square.on} 
            toggle={toggle} // customized onCLick for Box element, sirf funtion ka name pass kiya hai as a props
        />
    ))
    return (
        <main>
            {squareElements}
        </main>
    )
}
