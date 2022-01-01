import react from 'react'
import reactDom from 'react-dom'

class Hello extends react.Component{
    state = {
        count:0
    }
    onIncrement = e => {
        this.setState({
            count:e.target.value
        })
    }
    render(){
      return(
        <div>
            <div>Counter:{this.state.count}</div>
            <input type="text" value={this.state.count} onChange={this.onIncrement}></input>
            <button onClick={() => this.onIncrement()}>Click Me</button>
        </div>
        
      )
    }
}

export default Hello