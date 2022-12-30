import React, { Component } from 'react'
import { Container } from 'react-bootstrap';

export default class Home extends Component {
    
    constructor(){
        super();

        this.state = {
            x : 1
        }
    }

  
    render() {
    return (
      <Container>
        <h1 className='m-5'>Cocktailmaschine</h1>
        <p className='m-5'>Steueroberfläche der Cocktailmaschine</p>
      </Container>
    )
  }
}
