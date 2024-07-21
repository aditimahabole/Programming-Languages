import React, { useRef, useState } from "react";

const Form = () => {
  // State to hold form data
  const [formData, setFormData] = useState({
    firstName: "",
    lastName: "",
    age: "",
    gender: "",
    email: "",
    password: "",
  });

  // Refs for input fields
  const firstNameRef = useRef(null);
  const lastNameRef = useRef(null);
  const ageRef = useRef(null);
  const genderRef = useRef(null);
  const emailRef = useRef(null);
  const passwordRef = useRef(null);

  // Handle input change
  const handleChange = (e) => {
    const { name, value } = e.target;
    setFormData((prevData) => ({
      ...prevData,
      [name]: value,
    }));
  };

  // Handle key press to move to the next input field
  const handleKeyPress = (e, nextRef) => {
    if (e.key === "Enter") {
      e.preventDefault();
      nextRef.current.focus();
    }
  };

  // Check if the form is complete
  const isFormComplete = Object.values(formData).every(
    (value) => value.trim() !== ""
  );

  // Handle form submission
  const handleSubmit = (e) => {
    e.preventDefault();
    alert("Form Submitted!");
  };

  return (
    <div>
      <form onSubmit={handleSubmit}>
        <div>
          <label htmlFor="firstName">First Name</label>
          <input
            type="text"
            id="firstName"
            name="firstName"
            value={formData.firstName}
            onChange={handleChange}
            onKeyDown={(e) => handleKeyPress(e, lastNameRef)}
            ref={firstNameRef}
            aria-label="First Name"
            required
          />
        </div>

        <div>
          <label htmlFor="lastName">Last Name</label>
          <input
            type="text"
            id="lastName"
            name="lastName"
            value={formData.lastName}
            onChange={handleChange}
            onKeyDown={(e) => handleKeyPress(e, ageRef)}
            ref={lastNameRef}
            aria-label="Last Name"
            required
          />
        </div>

        <div>
          <label htmlFor="age">Age</label>
          <input
            type="number"
            id="age"
            name="age"
            value={formData.age}
            onChange={handleChange}
            onKeyDown={(e) => handleKeyPress(e, genderRef)}
            ref={ageRef}
            aria-label="Age"
            required
          />
        </div>

        <fieldset>
          <legend>Gender</legend>
          <div>
            <label htmlFor="genderMale">
              <input
                type="radio"
                id="genderMale"
                name="gender"
                value="male"
                checked={formData.gender === "male"}
                onChange={handleChange}
                onKeyDown={(e) => handleKeyPress(e, emailRef)}
                aria-labelledby="genderLabel"
              />
              Male
            </label>
          </div>
          <div>
            <label htmlFor="genderFemale">
              <input
                type="radio"
                id="genderFemale"
                name="gender"
                value="female"
                checked={formData.gender === "female"}
                onChange={handleChange}
                onKeyDown={(e) => handleKeyPress(e, emailRef)}
                aria-labelledby="genderLabel"
              />
              Female
            </label>
          </div>
        </fieldset>

        <div>
          <label htmlFor="email">Email</label>
          <input
            type="email"
            id="email"
            name="email"
            value={formData.email}
            onChange={handleChange}
            onKeyDown={(e) => handleKeyPress(e, passwordRef)}
            ref={emailRef}
            aria-label="Email"
            required
          />
        </div>

        <div>
          <label htmlFor="password">Password</label>
          <input
            type="password"
            id="password"
            name="password"
            value={formData.password}
            onChange={handleChange}
            ref={passwordRef}
            aria-label="Password"
            required
          />
        </div>

        <div>
          <button
            type="submit"
            disabled={!isFormComplete}
            aria-disabled={!isFormComplete}
          >
            Submit
          </button>
        </div>
      </form>
    </div>
  );
};

export default Form;
