import React, { Component } from 'react'

export class Button extends Component {
 render() {
  return (
      <div>

      <div>
    <button onClick={this.props.getNext} className='nextBtn'
      type='button'>>>>>></button>
      </div></div>
   )
 }
}

export default Button;