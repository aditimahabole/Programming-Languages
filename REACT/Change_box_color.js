// BOX COMPONENT
import React from "react"
export default function Box(props) {
    const [self,setSelf] = React.useState(props.on)
    function changeColor()
    {
        setSelf(prevState => !prevState )
        console.log("state chnged")
    }
    const styles = {
        backgroundColor: self ? "#222222" : "transparent"
    }
    return (
        <div style={styles} onClick = {changeColor} className="box"></div>
    )
}
// ------------------------------------------------------------------------------------------
// APP COMPONENT
import React from "react"
import boxes from "./boxes"
import Box from "./Box"

export default function App() {
    const [squares, setSquares] = React.useState(boxes)
//     pehle humne data ko square variable me store kara 
    
    const squareElements = squares.map(square => (
        <Box key={square.id} on={square.on} />
    ))
// fir humne har data ko map kara / iterate kara and hum show kar rhe
// Box yaha componenet hai 
    return (
        <main>
            {squareElements}
        </main>
    )
}
