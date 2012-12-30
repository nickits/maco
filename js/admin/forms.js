//window.addEvent('domready', function(){

var EditForm = new Class({
	initialize: function(params){
		this.entity = params.entity;
		this.myForm = null;
		this.formFields = {};
		this.grid = params.grid;
	},
	execute: function(id){
		$('modal_frame').addClass('show');
		$('form_frame').addClass('show');
		if(id == 0 && this.form != undefined){
			this.form.data = {};
			this.load();
		}
		else{
			var jsonRequest = new Request.JSON({url: 'forminit/' + this.entity + '/' + id , onSuccess: function(form){
				this.form = form;
				this.load();
			}.bind(this)}).get();
		}
	},
	load: function(){
		if(this.myForm != null)	this.myForm.destroy();
		this.myForm = new Element('form', {
			id:"myForm",
			action:"formpost/" + this.entity,
			method:"post"
		});

		$('form_container').adopt([this.myForm, new Element('div#myResult')]);
		this.fieldset = this.myForm;
		if(this.form.fieldset){
			var legend = new Element("legend", {text: this.form.fieldset});
			this.fieldset = new Element("fieldset");
			this.fieldset.inject(this.myForm);
			legend.inject(this.fieldset);
		}

		this.ul = new Element('ul');
		this.ul.inject(this.fieldset);
		Array.each(this.form.structure, function(element, index){
			var li = new Element('li');
			li.inject(this.ul);
			if(element.tag == "group"){
				Array.each(element.params, function(element, index){
					var el = new Element(element.tag, element.params);
					el.inject(this);
				}, li);
			}
			else if(element.tag == "select"){
				var el = new Element(element.tag, element.params);
				el.inject(li);
				Array.each(element.options, function(element, index){
					var el = new Element(element.tag, element.params);
					el.inject(this);
				}, el);
				if(typeof(element.params.name) != undefined){
					if(this.form.data[element.params.name] != undefined){
						el.value = this.form.data[element.params.name];
					}
				}
			}
			else{
				var el = new Element(element.tag, element.params);
				el.inject(li);
				if(typeof(element.params.name) != undefined && (element.tag == "input" || element.tag == "textarea")){
					if(this.form.data[element.params.name] != undefined){
						el.value = this.form.data[element.params.name];
					}
				}
			}  
		}, this); 

		var bContainer = new Element("div");
		var liContainer = new Element("li");
		this.ul.adopt([new Element("li"), liContainer]);
		bContainer.inject(liContainer);

		Array.each(this.form.buttons, function(element, index){
			var el = new Element(element.tag, element.params);
			el.inject(this);
			if(element.params.event == "close"){
				el.addEvent('click', function(){
					$('modal_frame').removeClass('show');
					$('form_frame').removeClass('show');
				});
			}
		}, bContainer); 

		// Labels over the formFields.
		this.myForm.getElements('[type=text], textarea').each(function(el){
			new OverText(el);
		});

		// Validation.
		new Form.Validator.Inline(this.myForm);

		// Ajax (integrates with the validator).
		var fRequest = new Form.Request(this.myForm, myResult, {
			requestOptions: {
		'spinnerTarget': this.myForm
			},
			extraData: { // This is just to make this example work.
		'html': 'Form sent.'
			}
		});  
		
		fRequest.addEvent('success', function(target, text, xml){
			this.grid.datagrid.loadData();
		}.bind(this));		
	}
});