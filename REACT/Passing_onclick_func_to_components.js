// import React from "react"
// THIS IS STAR.js
// export default function Star(props) {
//     const starIcon = props.isFilled ? "star-filled.png" : "star-empty.png"
//     return (
//         <img 
//             src={`../images/${starIcon}`} 
//             className="card--favorite"
//             onClick={props.handleClick}
////            here we can see props.handleCLick is actually toggleFavorite 
//         />
//     )
// }
// -------------------------------------------------------------------------------------------------------


import React from "react"
import Star from "./Star"
export default function App() {
    const [contact, setContact] = React.useState({
        firstName: "John",
        lastName: "Doe",
        phone: "+1 (719) 555-1212",
        email: "itsmyrealname@example.com",
        isFavorite: true
    })
    
    function toggleFavorite() {
        setContact(prevContact => ({
            ...prevContact,
            isFavorite: !prevContact.isFavorite
        }))
    }
    
    return (
        <main>
            <article className="card">
                <img src="./images/user.png" className="card--image" />
                <div className="card--info">
                    <Star isFilled={contact.isFavorite} handleClick={toggleFavorite} />
//       handleClick={toggleFavorite} this is customized props it will go to star.js and in that we will have a button and we can apply this function to that
// real onCLick
                    <h2 className="card--name">
                        {contact.firstName} {contact.lastName}
                    </h2>
                    <p className="card--contact">{contact.phone}</p>
                    <p className="card--contact">{contact.email}</p>
                </div>
                
            </article>
        </main>
    )
}
