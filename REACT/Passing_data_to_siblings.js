// export default function Header(props) {

//     return (
//         <header>
//             <p>Current user: props.user</p>
//         </header>
//     )
// }
// -------------------------------------------------
// import React from "react"
// export default function Body(props) {
//     return (
//         <section>
//             <h1>Welcome back,{props.user}!</h1>
//         </section>
//     )
// }
// -------------------------------------------------
import React from "react"
import Header from "./Header"
import Body from "./Body"

export default function App() {
    const [user, setUser] = React.useState("Joe")
//     as we need user value in both header and body compoenent so we will declare 
//     state in this app or main component
    
    return (
        <main>
            <Header user={user} />
            <Body user={user} />
        </main>
    )
}
