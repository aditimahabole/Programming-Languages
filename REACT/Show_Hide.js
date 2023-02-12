import React from "react"

export default function Joke(props) {
    const [show,setShow] = React.useState('Show')
    function Show(){
        setShow(show => show === 'Hide'? show = "Show": show = 'Hide')
    }
    return (
        <div>
            {props.setup && <h3>{props.setup}</h3>}
            {show ==='Hide'?<p>{props.punchline}</p>:<p></p>}
            <button onClick={Show} >{show} </button>
            <hr />
        </div>
    )
}
